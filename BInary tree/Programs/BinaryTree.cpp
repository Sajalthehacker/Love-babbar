#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data to create the node: " << endl;
    int data;
    cin >> data;

    // if data to be inserted is -1 then it means that node is NULL
    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the data to insert in left child of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to insert in right child of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // here NULL works as a seperator to shift the printing at next level

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level completely traverse ho chuka hain
            cout << endl;
            if (!q.empty())
            {
                // queue still have some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " " << endl if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrderIterative(Node* curr){
    stack<Node* > s;

    while(1){
        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            if(s.empty()){
                break;
            }
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}

void preOrderIterative(Node* root){
    stack<Node* > s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        
        cout<<temp->data<<" ";

        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

void postOrderIterative(Node* root){
    
}

void buildFromLOT(Node *&root)
{
    queue<Node *> q;
    cout << "Enter Data for root Node: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left child of " << temp->data << " " << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right child of " << temp->data << " " << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << "Level order traversal is: " << endl;
    LevelOrderTraversal(root);

    cout << "Inorder order traversal is: " << endl;
    inOrder(root);

    cout << "Preorder order traversal is: " << endl;
    preOrder(root);

    cout << "Post order traversal is: " << endl;
    postOrder(root);

    Node *root2 = NULL;
    buildFromLOT(root2);
    LevelOrderTraversal(root2);

    return 0;
}

// homework reverse level order traversal
// implement inorder preorder postorder using iteration
