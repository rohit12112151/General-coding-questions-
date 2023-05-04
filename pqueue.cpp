// #include<bits/stdc++.h>
// using namespace std;

// void heapify(int arr[],int n,int i)
// {
//      int largest=i;
//      int left=2*i+1;
//      int right=2*i+2;
//      if(arr[left]>arr[largest] && left<n)largest=left;
//      if(arr[largest]<arr[right] && right<n)largest=right;

//      if(largest!=i)
//      { 
//         swap(arr[i],arr[largest]);
//         heapify(arr,n,largest);
//      }
// }

// void heapsort(int arr[],int n)
// {
//     for(int i=n/2-1;i>=0;i--)heapify(arr,n,i);
    
//     for(int i=n-1;i>=0;i--)
//     {
//        swap(arr[i],arr[0]);
//        heapify(arr,i,0);
//     }
// }

// int main(){
 
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)cin>>arr[i];
//     heapsort(arr,n);
//     for(int i=0;i<n;i++)cout<<arr[i]<<" ";

// return 0;
// }






#include<bits/stdc++.h>
using namespace std;
class pqueue{
    public:
    int data;
    int priority;
 

};
pqueue pq[100];
int s=-1;

void pqpush(int val,int prio)
{
    s++;
    pq[s].data=val;
    pq[s].priority=prio;
}

int peek()
{
    int hp=INT16_MIN;
    int pk=-1;
    for(int i=0;i<=s;i++)
    {
       if(pq[i].priority>hp)
       {
        hp=pq[i].priority;
        pk=i;
       }
       else if(pq[i].priority==hp)
       {
        if(pq[i].data>pq[pk].data)pk=i;
       }
    }
    return pk;
}



void dqueue()
{
    for(int i=peek();i<s;i++)
    {
        pq[i]=pq[i+1];
    }
    s--;
}


int main(){
 
     
    int k=100;
    while(k--)
    {
        int val,p;cin>>val>>p;
        if(val==0,p==0)break;
        pqpush(val,p);
    }
    
    int x=peek();
    cout<<x<<endl;
    cout<<s+1<<endl;
    dqueue();
    cout<<s+1;
     
     
return 0;
}