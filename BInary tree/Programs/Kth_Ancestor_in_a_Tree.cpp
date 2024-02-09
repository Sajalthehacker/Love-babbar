/*
Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

Example 1:



Input:
K = 2 Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.
Example 2:

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.
Your Task:
You are asked to complete the function kthAncestor() which accepts root of the tree, k and node as input parameters, and returns the kth ancestor of Node which contains node as its value.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=105
1<= K <= 100
1 <= Node.data <= N

*/

// Node* solve(Node* root, int node, vector<int> &path){
//     if(root == NULL){
//         return root;
//     }
//     path.push_back(root->data);
//     if(root->data == node){
//         return root;
//     }
//     Node* leftAns = solve(root->left, node, path);
//     if(leftAns != NULL){
//         return leftAns;
//     }
//     Node* rightAns = solve(root->right, node, path);
//     if(rightAns == NULL){
//         path.pop_back();
//     }
//     return rightAns;
// }

// int kthAncestor(Node *root, int k, int node)
// {
//     // Code here
//     vector<int> path;
//     solve(root, node, path);
//     int n = path.size();
//     for(int i = n - 1; i >= 0; i--){
//         if(k == n - i - 1){
//             return path[i];
//         }
//     }
//     return -1;
// }

Node* solve(Node *root, int &k, int node){
    if(root == NULL || root->data == node){
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node){
    Node* ans = solve(root, k, node);
    if(ans == NULL){
        return -1;
    }
    else{
        return ans->data;
    }
}
