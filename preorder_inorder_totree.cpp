#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int inorder[],int start,int end,int curr)
{
      for(int i=start;i<=end;i++)
      {
        if(inorder[i]==curr)return i;
      }
      return -1;
}

node*buildtree(int preorder[],int inorder[],int start,int end)
{
    static int idx=start;
    if(start>end)return NULL;
    int curr=preorder[idx];
    node*box=new node(curr);
    idx++;
    if(start==end)return box;
    int pos=search(inorder,start,end,curr);
    box->left=buildtree(preorder,inorder,start,pos-1);
    box->right=buildtree(preorder,inorder,pos+1,end);
    return box;

}

void printinorder(node*root)
{
    if(root==NULL)return;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);

}

int main(){
 
    int n;
    cin>>n;
    int preorder[n];
    int inorder[n];

    for(int i=0;i<n;i++)cin>>preorder[i];
    for(int i=0;i<n;i++)cin>>inorder[i];

    node*root=buildtree(preorder,inorder,0,n-1);
    printinorder(root);
     
return 0;
}