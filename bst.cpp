// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int data;
//     node*left;
//     node*right;

//     node(int val)
//     {
//         data=val ;
//         left=NULL;
//         right=NULL;
//     }
// };

// node* insertnode(node*&root ,int val)
// {
    
   

//     if(root==NULL){return new node(val);}

//     if(val<root->data)
//     {
//       root->left=insertnode(root->left , val);
//     }
//     else
//     {
//         root->right=insertnode(root->right , val);
//     }

//     return root;
// }


// bool search(node*root , int key)
// {
//     if(root==NULL)return false;

//     if(root->data==key){
//         return true;
//     }
//     if(key<root->data)search(root->left , key);
//     else search(root->right , key);

//     return false;
// }

// node*inordersucc(node*root)
// {
//     node*curr=root;
//     while(curr && curr->left!=NULL)
//     {
//         curr=curr->left;
//     }
//     return curr;
// }

// node*deletenode(node*root , int key)
// {
//     if(key<root->data)root->left=deletenode(root->left , key);
//     else if(key>root->data)root->right=deletenode(root->right , key);
//     else{
//         if(root->left==NULL)
//         {
//             node*temp=root->right;
//             free(root);
//             return temp;
//         }
//         else if(root->right==NULL)
//         {
//             node*temp=root->left;
//             free(root);
//             return temp;
//         }
        
//         node*temp=inordersucc(root->right);
//         root->data=temp->data;
//         root->right=deletenode(root->right , temp->data);

//     }
//         return root;
// }

// void printinorder(node*root)
// {
//     if(root==NULL)return;
//     printinorder(root->left);
//     cout<<root->data<<" ";
//     printinorder(root->right);
// }

// void preorder(node*root)
// {
//     if(root==NULL)return;
//     cout<<root->data;
//     preorder(root->left);
//     preorder(root->right);
// }

// int main(){
  
// node*root=NULL;
// int n;
// cin>>n;
// while(n--)
// {
//     int val;
//     cin>>val;
//     root=insertnode(root,val);
// }


// printinorder(root);

// node*get=inordersucc(root);
// cout<<get->data;
// // node*s=search(root , 3);
// // if(s!=NULL)cout<<"found";
// // else cout<<"not found";

// // root=deletenode(root,2);
// // printinorder(root);


// return 0;
// }







#include<bits/stdc++.h>
using namespace std;

 class node {
    public:
    int data;
    node*next;
    bool visited;

    node(int val)
    {
        data=val;next=NULL;visited=false;
    }
 };

 void dfs(node*arr[],node*n,stack<node*>&st)
 {
    n->visited=true;
    node*p=n;
    while(p!=NULL)
    {
        if(arr[n->data]->visited==0)dfs(arr,arr[p->data],st);
        p=p->next;
    }
 }

int main(){
 
     int n,m;
     cin>>n>>m;
     node*arr[n];
     node*arrt[n];
     for(int i=1;i<=n;i++)arr[i]=new node(i);
     for(int i=1;i<=n;i++)arrt[i]=new node(i);

     for(int i=1;i<=m;i++)
     {
        int x,y;
        cin>>x>>y;

        node*p=new node(y);
        node*temp=arr[x];
        while(temp!=NULL)temp=temp->next;temp->next=p;

        node*p2=new node(x);
        node*temp=arr[y];
        while(temp!=NULL)temp=temp->next;temp->next=p2;

        stack<node*>st;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]->visited==0)dfs(arr,arr[i],st);
        }
     }
     
return 0;
}