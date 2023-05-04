#include<bits/stdc++.h>
using namespace std;

void posttoinfix(string str)
{
    stack<int>st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>'0' && str[i]<='9')
        {
            st.push(str[i]-48);
        }

        else if(str[i]=='-' || str[i]=='+' || str[i]=='*' || str[i]=='/')
        {
             if(str[i]=='+')
             {
                int x=st.top();
                st.pop();
                st.top()+=x;
             }
             if(str[i]=='-')
             {
                int x=st.top();
                st.pop();
                st.top()-=x;
             }
             if(str[i]=='*')
             {
                int x=st.top();
                st.pop();
                st.top()*=x;
             }
             if(str[i]=='/')
             {
                int x=st.top();
                st.pop();
                st.top()/=x;
             }

        }
    }
    cout<<st.top();
}

int main(){
 
    
     
    posttoinfix("257+*6+");
     
return 0;
}