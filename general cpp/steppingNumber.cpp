#include<bits/stdc++.h>
using namespace std;

//stepping number, where the difference between the digits of the number should be equal to 1 ,if number greater than or equal to 10
bool checker(int n)
{
    int prev=-1;
    while( n )
    {
        int cur=n%10;

        if( prev==-1 )
            prev=cur;

        else
        {
            if( abs(prev-cur)!=1 )
                return false;
        }
        prev=cur;
        n=n/10;
    }
    return true;
}

int main()
{
    int n=5,m=32;

    for(int i=n;i<=m;i++)
    {
        if( checker(i) )
            cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}