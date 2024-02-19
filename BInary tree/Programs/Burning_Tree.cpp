// Mimimum time to burn a binary tree
/*
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Example 1:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value
8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    /
 8    10
Target Node = 10
Output: 5

Your Task:
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 104

approach -> create node to parent mapping
            find target node in the tree
            start burning the tree from target node
*/

Node* createNodeToParentMapping(Node* root, int target, unordered_map<Node*, Node*>& nodeToParent){
    Node* targetNode = NULL;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front->data == target){
            targetNode = front;
        }

        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }        
    }

    return targetNode;
}

void burnTree(Node* targetNode, unordered_map<Node*, Node*> nodeToParent, int &ans){
    queue<Node* > q;
    unordered_map<Node*, bool> visited;

    q.push(targetNode);
    visited[targetNode] = true;

    while(!q.empty()){
        int size = q.size();
        bool isPushInQueue = false;

        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();

            if(temp->left && !visited[temp->left]){
                visited[temp->left] = true;
                q.push(temp->left);
                isPushInQueue = true;
            }

            if(temp->right && !visited[temp->right]){
                visited[temp->right] = true;
                q.push(temp->right);
                isPushInQueue = true;
            }

            Node* parent = nodeToParent[temp];
            if(parent && !visited[parent]){
                visited[parent] = true;
                q.push(parent);
                isPushInQueue = true;
            }
        }

        if(isPushInQueue){
            ans++;
        }
    }
}

int minTime(Node *root, int target)
{
    // Your code goes here
    unordered_map<Node*, Node*> nodeToParent;
    Node* targetNode = createNodeToParentMapping(root, target, nodeToParent);
    int ans = 0;
    burnTree(targetNode, nodeToParent, ans);
    return ans;
}

// time complexity -> O(N)
// space complexity -> O(N)