// Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.Example 2:

// Input :
//        10
//       /  \
//      20   30
//     / \ 
//    40  60

// Output: 40 60 20 30 10
// Explanation:
// Traversing level 2 : 40 60
// Traversing level 1 : 20 30
// Traversing level 0 : 10

vector<int> ReverseLOT(Node* root){
    queue<Node* > q;
    stack<int> s;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        s.push(temp->data);

        if(temp->right){
            q.push(temp->right);
        }

        if(temp->left){
            q.push(temp->left);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// time complexity -> O(N)
// space complexity -> O(N)