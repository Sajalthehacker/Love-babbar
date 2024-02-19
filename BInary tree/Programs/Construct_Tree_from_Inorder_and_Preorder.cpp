/*
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal.

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000
*/

// int findPos(vector<int> in, int data, int n){
//     for(int i = 0; i < n; i++){
//         if(data == in[i]){
//             return i;
//         }
//     }
//     return -1;
// }

// Node* solve(vector<int> in, vector<int> pre, int n, int &preOrderIndex, int in_start, int in_end){
//     if(in_end < in_start || preOrderIndex >= n){
//         return NULL;
//     }
//     Node* root = new Node(pre[preOrderIndex++]);
//     Node* inOrderPosition = findPos(in, root->data, n);

//     root->left = solve(in, pre, n, preOrderIndex, in_start, inOrderPosition - 1);
//     root->right = solve(in, pre, n, preOrderIndex, inOrderPosition + 1, in_end);

//     return root;
// }

// Node *buildTree(vector<int> in, vector<int> pre, int n)
// {
//     // Code here
//     int preOrderIndex = 0;
//     int in_start = 0, in_end = n - 1;
//     Node* ans = solve(in, pre, n, preOrderIndex, in_start, in_end);
//     return ans;
// }

// now we do some optimization in above code
// we make a unordered_map that stores mapping of all indexes of elements of inorder array to eliminate calls to findPos() function


Node* solve(vector<int> in, vector<int> pre, int n, int &preOrderIndex, int in_start, int in_end, unordered_map<int, int> mp){
    if(in_end < in_start || preOrderIndex >= n){
        return NULL;
    }
    Node* root = new Node(pre[preOrderIndex++]);
    Node* inOrderPosition = mp[root->data];

    root->left = solve(in, pre, n, preOrderIndex, in_start, inOrderPosition - 1, mp);
    root->right = solve(in, pre, n, preOrderIndex, inOrderPosition + 1, in_end, mp);

    return root;
}

Node *buildTree(vector<int> in, vector<int> pre, int n)
{
    // Code here
    int preOrderIndex = 0;
    int in_start = 0, in_end = n - 1;
    unordered_map<int, int> mp;

    for(int i = 0, i < n; i++){
        mp[in[i]] = i;
    }

    Node* ans = solve(in, pre, n, preOrderIndex, in_start, in_end, mp);
    return ans;
}

// time complexity :- O(N)
// space complexity :- o(N)