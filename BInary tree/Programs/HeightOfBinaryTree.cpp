// height ar max - depth of binary tree
// given a binary tree find its height
// height = number of nodes in longest path from root node to a leaf node

// first way

int solve(Node *root, int cnt)
{
    if (root == NULL)
    {
        return cnt;
    }
    return max(solve(root->left, cnt), solve(root->right, cnt)) + 1;
}

int height(Node *root)
{
    int cnt = 0;
    return solve(root, cnt);
}

// second way

// int height1(Node* root){
//     if(root == NULL){
//         return 0;
//     }

//     int lefth = height1(root->left);
//     int righth = height1(root->right);

//     return (max(lefth, righth) + 1);
// }

// time complexity -> O(n)
// space complexity -> O(height)
