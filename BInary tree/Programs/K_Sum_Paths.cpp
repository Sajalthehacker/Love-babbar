/*
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.

Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 
2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 
8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
Your Task:  
You don't need to read input or print anything. Complete the function sumK() which takes root node and integer K as input parameters and returns the number of paths that have sum K. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)
*/

// class Solution{
//   public:
//     int helper(Node* root, int k, int sum){
//         int count = 0;
//         if(root == NULL){
//             return count;
//         }
//         sum = sum + root->data;
//         if(sum == k){
//             count++;
//         }
//         count = count + helper(root->left, k, sum);
//         count = count + helper(root->right, k, sum);

//         return count;
//     }
//     void solve(Node *root, int k, int &ans){
//         if(root == NULL){
//             return;
//         }
//         int temp = helper(root, k, 0);
//         ans = ans + temp;
//         solve(root->left, k, ans);
//         solve(root->right, k, ans);
//     }
//     int sumK(Node *root,int k)
//     {
//         if(root == NULL){
//             return 0;
//         }
//         int ans = 0;
//         solve(root, k, ans);
//         return ans;
//     }
// };

// time complexity -> O(N ^ 2)
// space complexity -> O(H)

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector
    }
};
