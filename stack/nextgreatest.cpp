#include<bits/stdc++.h>
using namespace std;

void next_greatest(int a[],int n)
{
    stack<int> st;
    st.push(a[0]);

    for(int i=1;i<n;i++)
    {
        if(st.empty())
        {
            st.push(a[i]);
        }
        
    }
}

int main()
{
    int a[]={1,3,5,9,6,7};
    int n=sizeof(a)/sizeof(0);
    next_greatest(a,n);
    return 0;
}