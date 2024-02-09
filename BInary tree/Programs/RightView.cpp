void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    // we arrived at a new level 
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}
vector<int> RightView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// homework -> diagonal traversal of binary tree
// hint -> right child me jaane pe horizontal distance change mat karna and left child jaane pe horizontal distance decrement kar dena 
