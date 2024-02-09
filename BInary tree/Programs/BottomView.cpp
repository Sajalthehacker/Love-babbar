vector<int> BottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // map<horizontal_distance, node->data>
    map<int, int> nodes;
    // queue<pair<node, horizontal_distance> >
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int Horizontal_Distance = temp.second;

        nodes[Horizontal_Distance] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, Horizontal_Distance - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, Horizontal_Distance + 1));
        }
    }

    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }

    return ans;
}