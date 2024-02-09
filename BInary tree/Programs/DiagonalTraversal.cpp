/*
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4


*/

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, vector<int>> nodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int Horizontal_Distance = temp.second;

        nodes[Horizontal_Distance].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, Horizontal_Distance - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, Horizontal_Distance));
        }
    }

    for(auto i : nodes){
        for(auto j: i.second){
            ans.push_back(j);
        }
    }

    return ans;
}