#include<iostream>
#include<vector>

using namespace std;

class node{
    public:
    int val;
    node* right;
    node* left;

    node(int data){
        this->val=data;
        this->left=this->right=NULL;

    }
};

int position(vector<int> &in,int ele){

    for(int i=0;i<in.size();i++){
        if(in[i]==ele){
            return i;
        }
    }
}

node* build(vector<int> &in,vector<int> &pre,int st,int en){
    static int idx=0;
   if(st>en) return NULL;


   node* newnode= new node(pre[idx]);
   int pos=position(in,pre[idx]);
 idx++;


  if(st==en) return newnode;

   newnode->left=build(in,pre,st,pos-1);
   newnode->right=build(in,pre,pos+1,en);

   return newnode;
}

void inorder(node* root){

    if(root==NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


int main(){
    vector<int> in;
    vector<int> pre;

    int p,i;
    cin>>p;

    for(int j=0;j<p;j++){
        int ele;
        cin>>ele;
        pre.push_back(ele);
    }
    for(int j=0;j<p;j++){
        int ele;
        cin>>ele;

        in.push_back(ele);
    }

   node* root=NULL;

   root=build(in,pre,0,p-1);

   inorder(root);
}
