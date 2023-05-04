 #include<bits/stdc++.h>
 using namespace std;

// int precedence(char ch)
// {
//     if(ch=='^')return 3;
//     else if(ch=='*' || ch=='/')return 2;
//     else if(ch=='+' || ch=='-')return 1;
//     else return -1;
// }

// void infixtopostfix(string s)
// {
//     stack<char>st;

//     string result="";
//     for(int i=0;i<s.size();i++)
//     {
//         char c=s[i];
//         if((c>='a' && c<='z') || (c>='A' && c<='Z'))result+=c;

//         else if(c=='(')st.push('(');

//         else if(c==')')
//         {
//             while(st.top()!='('){result+=st.top();st.pop();}st.pop();
//         }

//         else
//         {
//              while(!st.empty()  && precedence(c)<=precedence(st.top()))
//              {
//                 if(c=='^' && st.top()!='^')break;
//                 else{
//                     result+=st.top();st.pop();
//                 }
//              }
//         st.push(c);
//         }

//     }
//     while(!st.empty())
//     {
//         result+=st.top();st.pop();
//     }

//     cout<<result<<endl;
// }

// int main(){

//  string str = "(a+b)*c";
//     infixtopostfix(str);

// return 0;
// }

// class Solution
// {
// public:
//     int prec(char c)
//     {
//         // if(c=='^')return 3;
//         if (c == '*' || c == '/')
//             return 2;
//         if (c == '+' || c == '-')
//             return 1;
//         return -1;
//     }
//     int calculate(string s)
//     {

//         stack<char> st;
//         string str = "";
//         // str+='p';

//         for (int i = 0; i < s.size(); i++)
//         {
//             char ch = s[i];

//             if (ch >= '0' && ch <= '9')
//                 str += ch;
//             else if (ch == '(')
//                 st.push('(');
//             else if (ch == ')')
//             {
//                 while (st.top() != '(')
//                 {
//                     str += st.top();
//                     st.pop();
//                 }
//                 st.pop();
//             }
//             else
//             {
//                 // if(c=='^' && st.top()!='^')break;
//                 while (!st.empty() && prec(ch) <= prec(st.top()))
//                 {
//                     if (ch == '^' && st.top() != '^')
//                         break;
//                     else
//                     {
//                         str += st.top();
//                         st.pop();
//                     }
//                 }
//                 st.push(ch);
//             }
//         }
//         while (!st.empty())
//         {
//             str += st.top();
//             st.pop();
//         }
//         cout << str;
//         stack<int> stk;
//         for (int i = 0; i < str.size(); i++)
//         {
//             if (str[i] >= '0' && str[i] <= '9')
//                 stk.push(str[i] - '0');
//             else
//             {

//                 if (str[i] == '*')
//                 {
//                     int a = stk.top();
//                     stk.pop();
//                     int b = stk.top();
//                     stk.pop();
//                     stk.push(a * b);
//                 }
//                 else if (str[i] == '/')
//                 {
//                     int a = stk.top();
//                     stk.pop();
//                     int b = stk.top();
//                     stk.pop();
//                     stk.push(b / a);
//                 }
//                 else if (str[i] == '+')
//                 {
//                     int a = stk.top();
//                     stk.pop();
//                     int b = stk.top();
//                     stk.pop();
//                     stk.push(a + b);
//                 }
//                 else if (str[i] == '-')
//                 {
//                     int a = stk.top();
//                     stk.pop();
//                     int b = stk.top();
//                     stk.pop();
//                     stk.push(b - a);
//                 }
//             }
//         }
//         cout << "hbhuvygv";
//         int ans = stk.top();
//         return ans;

//         // return 3;
//     }
// };


