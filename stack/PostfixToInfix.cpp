#include<bits/stdc++.h>
using namespace std;

string PostfixToInfix( string exp )
{
    stack<string> st;
    
    if( exp.length()<=1 )
    {
        cout<<"Empty string";
        exit(0);
    }

    for(int i=0;i<exp.length();i++)
    {
        if( (exp[i]>='a'&&exp[i]<='z') || (exp[i]>='A'&&exp[i]<='Z') || (exp[i]>='1'&&exp[i]<='9') )
        {
            string str(1,exp[i]);
            st.push(str);
        }
        else
        {
            string operand1=st.top();
            st.pop();
            string operand2=st.top();
            st.pop();
            st.push("("+operand1+exp[i]+operand2+")");
        }
    }
    return st.top();
}

int main()
{
    string exp="abcd^e-fgh*+^*+i-";
    cout<<PostfixToInfix(exp);
    return 0;
}