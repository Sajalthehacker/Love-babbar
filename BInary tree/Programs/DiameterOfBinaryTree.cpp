// diameter of tree sometimes called width
// diameter = number of nodes in the longest path between two end nodes. end nodes can be root node or leaf node

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefth = height(root->left);
    int righth = height(root->right);

    return (max(lefth, righth) + 1);
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    return max(op1, max(op2, op3));
}

// time complexity of above diameter function is O(n ^ 2) because height function is called at every node

// second way

// Now we are doing some optimizations

// here first value in this pair represents diameter and second value represents height
pair<int, int> diameterFast(Node *root)
{
    // NULL tree have 0 diameter and 0 height
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftD = diameterFast(root->left);
    pair<int, int> rightD = diameterFast(root->right);

    int op1 = leftD.first;
    int op2 = rightD.first;
    int op3 = leftD.second + 1 + rightD.second;

    pair<int, int> ans = make_pair(max(op1, max(op2, op3)), max(leftD.second, rightD.second) + 1);
    return ans;
}
int diameter(Node *root)
{
    return diameterFast(root).first;
}

// now the time complexity of above diameter function is O(n)
// space complexity is O(height)

// note - agar kisi function se 3 - 4 values return karni ho to apna ek user defined data type bana lo like class and usse aap return karwa sakte ho
// 10 - 100 value return karani ho toh array bana lo
