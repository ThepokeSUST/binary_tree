#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
      int data;
      node* left;
      node* right;

      node(int ele){
         this->data=ele;
         this->left=this->right=NULL;
      }
};

void inorder(node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


void level_order(node* root){
   queue<node*> q;

   q.push(root);
   q.push(NULL);
     
     while(!q.empty()){
         node* cur=q.front();
         q.pop();

         if(cur){
                cout<<cur->data<<" ";
              if(cur->left) q.push(cur->left);

               if(cur->right) q.push(cur->right);

         }
         else{
            if(!q.empty()){
                q.push(NULL);
            }
         }
     }
}


int main(){

    node* root=new node(9);

    root->left=new node(45);
    root->right=new node(5);

    root->left->left=new node(76);
    root->left->right=new node(23);

    root->right->left=new node(87);
    root->right->right=new node(21);
   
    inorder(root);

    cout<<endl;

    level_order(root);

}