// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
void Preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node *root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data;
    Inorder(root->right);
}
void Postorder(Node *root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data;
}


Node * BinaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    //root node create
    Node *temp=new Node(x);
    //left node create
    cout<<"enter left child of x"<<x<<" ";
    temp->left=BinaryTree();
    //right node create
    cout<<"enter right vhild of x"<<x<<" ";
    temp->right=BinaryTree();
    return temp;    
}
int main() {
          cout<<"Enter the root Node:";
          Node *root;
          root=BinaryTree();
          cout<<"preorder traversal \n";
          Preorder(root);
          cout<<"Inorder traversal \n";
          Inorder(root);
          cout<<"Postorder traversal \n";
          Postorder(root);
}