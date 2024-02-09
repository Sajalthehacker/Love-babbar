// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
/* 
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8

hum iss question ko teen part me solve karenge - 
1) pehle left boundary ko print karlenge (top to bottom) but execpt its leaf node
2) phir saari leaf nodes ko print kar lenge (left to right). take help from inorder traversal logic
3) phir right boundary ko print karlenge (bottom to top) but execpt its leaf node
4) ensure to consider and print leaf node only once
*/

// first part to print left boundary
void traverseLeft(Node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left, ans);
    }
    else{
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    else if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right, ans);
    }
    else{
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);

    return ans;
}