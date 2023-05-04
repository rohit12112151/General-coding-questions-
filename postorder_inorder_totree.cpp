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

node*buildtree(int postorder[],int inorder[],int start,int end)
{
    static int idx=end;
    if(start>end)return NULL;
    int curr=postorder[idx];
    idx--;
    node*m=new node(curr);
    if(start==end)return m;
    int pos=search(inorder,start,end,curr);
    m->left=buildtree(postorder,inorder,start,pos-1);
    m->right=buildtree(postorder,inorder,pos+1,end);
    return m;

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

  int postorder[n];
  int inorder[n];

  for(int i=0;i<n;i++)cin>>postorder[i];
  for(int i=0;i<n;i++)cin>>inorder[i];

  node*root=buildtree(postorder,inorder,0,n-1);
  printinorder(root);
     
return 0;
}