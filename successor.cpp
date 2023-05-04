#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node*parent;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

node*insertnode(node*&root,int val)
{
    if(root==NULL)return new node(val);
    if(root->data<val)
    {

        node*n=insertnode(root->right,val);
        root->right=n;
        n->parent=root;
    return root;
    }
    else {
         node*n=insertnode(root->left,val);
        root->left=n;
        n->parent=root;
    return root;
    }
}

void inorder(node*root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node*successor(node*root ,int val)
{
    if(root==NULL)return NULL;
    if(root->data==val)
    {
        if(root->right!=NULL)
        {
            node*rootr=root->right;
            while(rootr->left)rootr=rootr->left;
            return rootr;
        }
        else if(root->parent->left==root){return root->parent;
            // while(root->parent->parent->left!=root->parent)root=root->parent;
            // return root;
        }
    }
    if(val>root->data)successor(root->right,val);
    if(val<root->data)successor(root->left,val);
     
}

int main(){
 
    int k=11;
    node*root=NULL;
    while(k--)
    {
        int a;cin>>a;
        root=insertnode(root,a);
    }
    inorder(root);
    node*d=successor(root,11);
    cout<<d->data;
     
    
     
return 0;
}