class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == NULL && right == NULL){
            return NULL;
        }
        else if(left != NULL && right == NULL){
            return left;
        }
        else if(left == NULL && right != NULL){
            return right;
        }
        else{
            return root;
        }
    }
};

// time complexity -> O(N)
// space complexity -> O(H)