// given a binary tree, find if it is height balanced or not. A tree is height balanced if diffrence between height of left and right subtrees is not more than 1 for all nodes.
// abs(left height - right height) < 1

// int height(Node* root){
//     if(root == NULL){
//         return 0;
//     }

//     int lefth = height(root->left);
//     int righth = height(root->right);

//     return (max(lefth, righth) + 1);
// }

// bool isBalanced(Node* root){
//     if(root == NULL){
//         return true;
//     }

//     bool left = isBalanced(root->left);
//     bool right = isBalanced(root->right);
//     bool diff = (abs(height(root->left) - height(root->right)) <= 1);
//     return ((left && right) && diff);
// }

// time complexity of above function is O(n ^ 2) due to height() function call at every node

// now we do some optimization

pair<bool, int> isBalancedFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);
    bool diff = (abs(left.second - right.second) <= 1);

    pair<bool, int> ans = make_pair(((left.first && right.first) && diff), max(left.second, right.second) + 1);

    return ans;
}

bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}

// time complexity of above function is O(N)
