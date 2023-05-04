#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int val)
    {
        data=val;
        next=NULL;

    }
};

void makelist(node*&head)
{
    int n;
    cin>>n;
    node*m=new node(n);
    if(head==NULL){head=m;return;}
    node*temp=head;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=m;
}

void printlist(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void revlist(node*&head)
{
    node*prev=NULL;
    node*post=NULL;
    node*curr=head;
    while(curr!=NULL)
    {
        post=curr->next;
        curr->next=prev;
        prev=curr;
        curr=post;
    }
    head=prev;
}

void revadjnode(node*&head)
{
    int n=1;
    node*prev=NULL;
    node*post=NULL;
    node*ppost=NULL;
    node*curr=head;

    while(curr!=NULL)
    {
        post=curr->next;
        ppost=curr->next->next;
        post->next=curr;
        curr->next=ppost;
        prev=curr;
        prev->next=ppost;
        curr=ppost;
        if(n--)head=post;
    }
}


//merge sorted linked list
node*mergellist(node*&head1,node*&head2)
{
    node*temp1=head1;
    node*temp2=head2;
    node*head3=NULL;
    node*temp3=head3;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            node*m=new node(temp1->data);
            if(head3==NULL){head3=m;temp3=head3;}
            else{
                while(temp3->next!=NULL)temp3=temp3->next;
                temp3->next=m;
            }
            temp1=temp1->next;
        }

        else if(temp1->data>temp2->data)
        {
            node*m=new node(temp2->data);
            if(head3==NULL){head3=m;temp3=head3;}
            else{
                while(temp3->next!=NULL)temp3=temp3->next;
                temp3->next=m;
            }
            temp2=temp2->next;
        }

        else{
            node*m=new node(temp2->data);
            if(head3==NULL){head3=m;head3->next=m;temp3=head3;}
            else{
                while(temp3->next!=NULL)temp3=temp3->next;
                temp3->next=m;temp3=temp3->next;temp3->next=m;
            }
            temp1=temp1->next;
            temp2=temp2->next;

        }
    }
     while(temp1!=NULL)
     {
        temp3->next=temp1;
        temp3=temp3->next;
        temp1=temp1->next;
     }
     while(temp2!=NULL)
     {
        temp3->next=temp2;
        temp3=temp3->next;
        temp2=temp2->next;
     }
     return head3;
}

int main(){


    int n,m;
    cin>>n>>m;
    node*head=NULL;
    node*head1=NULL;
    while(n--)makelist(head);
    while(m--)makelist(head1);
    printlist(head);
    cout<<endl;
    printlist(head1);
    cout<<endl;
    node*head2=mergellist(head,head1);
    printlist(head2);
    // revlist(head);
    // printlist(head);
    // cout<<endl;
    // revadjnode(head);
    // printlist(head);
    // cout<<endl;
 
    
     
return 0;
}