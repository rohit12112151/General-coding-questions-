#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int val)
    {
        data=val ;
        left=NULL;
        right=NULL;
    }
};

node* insertnode(node*&root ,int val)
{
    
   

    if(root==NULL){return new node(val);}

    if(val<root->data)
    {
      root->left=insertnode(root->left , val);
    }
    else
    {
        root->right=insertnode(root->right , val);
    }

    return root;
}


node*search(node*root , int key)
{
    if(root==NULL)return NULL;

    if(root->data==key){
        return root;
    }
    if(key<root->data)search(root->left , key);
    else search(root->right , key);
}

node*inordersucc(node*root)
{
    node*curr=root;
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

node*deletenode(node*root , int key)
{
    if(key<root->data)root->left=deletenode(root->left , key);
    else if(key>root->data)root->right=deletenode(root->right , key);
    else{
        if(root->left==NULL)
        {
            node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node*temp=root->left;
            free(root);
            return temp;
        }
        
        node*temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right , temp->data);

    }
        return root;
}

void printinorder(node*root)
{
    if(root==NULL)return;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

int main(){
  
node*root=NULL;
int n;
cin>>n;
while(n--)
{
    int val;
    cin>>val;
    root=insertnode(root,val);
}


printinorder(root);

node*get=inordersucc(root);
cout<<get->data;
// node*s=search(root , 3);
// if(s!=NULL)cout<<"found";
// else cout<<"not found";

// root=deletenode(root,2);
// printinorder(root);


return 0;
}