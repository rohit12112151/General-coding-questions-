#include<bits/stdc++.h>
using namespace std;

class person{
    public:
    int age;
    float height;

    person(int a,float h)
    {
        age=a;
        height=h;
    }
};

bool operator < (person p1,person p2)
{
    return p1.age<p2.age;
}

int main(){

    priority_queue<person>pq;
 
     int age=1;float height=1;
     while(age>0)
     {
        cin>>age>>height;
        if(age<0)break;
        pq.push(person(age,height));
     }

     while(!pq.empty())
     {
        cout<<pq.top().age<<" "<<pq.top().height<<endl;
        pq.pop();
     }
     
    
     
return 0;
}