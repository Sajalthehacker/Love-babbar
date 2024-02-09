// Given a binary tree. return true if, for every node X in the tree other than the leaf nodes, its value is equal to sum of its left subtree's values and sum of its right subtree's values else returns false
// an empty tree is a sum tree and leaf node alone is considered as a sum tree

pair<bool, int> isSumTreeFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    else if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    pair<bool, int> ans = make_pair((left.first && right.first && (left.second + right.second == root->data)), left.second + right.second + root->data);
    return ans;
}

bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}