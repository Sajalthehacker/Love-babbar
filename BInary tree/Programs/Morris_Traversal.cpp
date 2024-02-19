/*
current = root
while(root != NULL){
    if(left child not exists){
        visit current node 
        current = current ->right
    }
    else{
        predecessor = find(curr)
        if(predecessor->right == NULL){
            predecessor->right = current;
            current = current->left;
        }
        else{
            predecessor->right = NULL
            visit current node
            current = current->right;
        }
    }
}
*/