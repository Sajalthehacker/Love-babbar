vector<int> LeftView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    // map<level, node->data> 
    map<int, int> nodes;
    // queue<pair<node, level> >
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int Level = temp.second;

        if(nodes.find(Level) == nodes.end()){
            nodes[Level] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, Level + 1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, Level + 1));
        }
    }

    for(auto i : nodes){
        ans.push_back(i.second);
    }

    return ans;
}

// time complexity -> O(N LOG(N))

// Optimal solution 
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    // we arrived at a new level 
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> LeftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}


// make recursive call stack and recursive tree for above function