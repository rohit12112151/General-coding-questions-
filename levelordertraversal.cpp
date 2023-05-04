#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void levelorder(node *root)

{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            cout << n->data << " ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}


int sumatklevel(node*root)
{
    if(root==NULL)return 0;
    int l;
    cin>>l;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int level=0;

    while(!q.empty())
    {
        node*n=q.front();q.pop();
       if(n!=NULL)
       {
       if(level==l)
        sum=sum+n->data;
        if(n->left)q.push(n->left);
        if(n->right)q.push(n->right);
       }
       else if(!q.empty())
       {
        q.push(NULL);
        level++;
       }
    }
    return sum;
}


int totalnodeinBT(node*root)
{
    if(root==NULL)return 0;
    return totalnodeinBT(root->left)+totalnodeinBT(root->right)+1;
}

int height(node*root)
{
    if(root==NULL)return 0;
    return max(height(root->left),height(root->right))+1;
}


int diameter(node*root)
{
    if(root==NULL)return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
  int  currdiameter=lheight+rheight+1;
  return max(currdiameter,max(diameter(root->left),diameter(root->right)));
}


void sumreplacement(node*root)
{
    if(root==NULL)return;

    sumreplacement(root->left);
    sumreplacement(root->right);
    if(root->left!=NULL)root->data+=root->left->data;
    if(root->right!=NULL)root->data+=root->right->data;
}

void preorder(node*root)
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

bool isbalheight(node*root)
{
    if(root==NULL)return true;
    if(isbalheight(root->left)==false)return false;
    if(isbalheight(root->right)==false)return false;
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(lheight-rheight<=1)return true;
    else return false;
}

void rightview(node*root)
{
    if(root==NULL)return;

    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
            node*n=q.front();
            q.pop();
        if(n!=NULL)
        {
            if(q.front()==NULL)cout<<n->data<<" ";
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}


//
void leftview(node*root)
{
    if(root==NULL)return;

    queue<node*>q;
    // q.push(NULL);
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
            node*n=q.front();
            q.pop();
             
         if(n!=NULL)
        {
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);
        }
        else if(!q.empty())
        {
            cout<<q.front()->data<<" ";
            q.push(NULL);
        }
       
    }
}


node*LCA(node*root,int n1,int n2)
{
    if(root==NULL)
    return NULL;
    if(root->data==n1 || root->right==NULL)return root;
    node*left=LCA(root->left,n1,n2);
    node*right=LCA(root->right,n1,n2);
    
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    node*root2=new node(1);
    root2->left=new node(2);
    root2->left->left=new node(3);


    levelorder(root);
    cout<<endl;
    cout<<sumatklevel(root);
    cout<<endl;
    cout<<totalnodeinBT(root)<<endl;
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    sumreplacement(root);
    preorder(root);
    cout<<endl;
    cout<<isbalheight(root)<<endl;
    rightview(root2);
    cout<<endl;
    leftview(root2);


    return 0;
}