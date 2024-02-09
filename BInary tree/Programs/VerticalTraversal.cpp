/*
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9
Output:
4 2 1 5 6 3 8 7 9

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
*/

vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // map<horizontal_distance, map<level, vector_of_nodes> > >
    map<int, map<int, vector<int>>> nodes;
    // queue<pair<Node*, pair<horizontal_distance, level> > >
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int Horizontal_Distance = temp.second.first;
        int Level = temp.second.second;

        nodes[Horizontal_Distance][Level].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(Horizontal_Distance - 1, Level + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(Horizontal_Distance + 1, Level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}