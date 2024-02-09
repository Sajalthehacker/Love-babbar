/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

        1
     /    \
   2       3
  / \    /  \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Input:
      1
   /    \
  2      3
Output: 2 1 3

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
*/

vector<int> TopView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    // map<horizontal_distance, node->data> 
    map<int, int> nodes;
    // queue<pair<node, horizontal_distance> >
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int Horizontal_Distance = temp.second;

        if(nodes.find(Horizontal_Distance) == nodes.end()){
            nodes[Horizontal_Distance] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, Horizontal_Distance - 1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, Horizontal_Distance + 1));
        }
    }

    for(auto i : nodes){
        ans.push_back(i.second);
    }

    return ans;
}