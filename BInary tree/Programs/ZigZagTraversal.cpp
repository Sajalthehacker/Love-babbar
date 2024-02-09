// zig zag tarversal or spiral traversal of binary tree

// Input:
//         1
//       /   \
//      2     3
//     / \   /  \
//    4   5 6    7
// Output:
// 1 3 2 4 5 6 7

vector<int> ZigZagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    bool LeftToRight = true;

    while (!q.empty())
    {
        // find number of nodes in a level
        int size = q.size();
        vector<int> ans(size, 0);

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            // using ternary operator deciding normal insert or reverse insert
            int index = LeftToRight ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        // Alternate the diraction 
        LeftToRight = !LeftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
        ans.clear();
    }
    return result;
}