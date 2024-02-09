void inOrder(Node *root, int &cnt)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
    }
    inOrder(root->right);
}

int NumberOfLeafNodes(Node *root)
{
    int cnt = 0;
    inOrder(root, cnt);
    return cnt;
}