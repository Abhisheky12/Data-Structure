#include <iostream>
using namespace std;
#include<queue>
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
int main() {
    int x;
    cout<<"enter the root element";
    cin>>x;
    int first;
    int second;
     queue<Node*>q;
     //creting root node
     Node *root=new Node(x);
     q.push(root);
     //creting binary tree
     while(!q.empty())
     {
         Node *temp=q.front();
         q.pop();
         //left node
         cout<<"left node child of"<<temp->data;
         cin>>first;
         if(first!=-1)
         {
         temp->left=new Node(first);
         q.push(temp->left);
         }
         //right node
         cout<<"right child of"<<temp->data;
         cin>>second;
         if(second!=-1)
         {
         temp->right=new Node(second);
         q.push(temp->right);
         }
}
    return 0;
}