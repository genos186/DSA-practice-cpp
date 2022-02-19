#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str="momm";
    int n=str.size();
    int x=1;
    for( int i=0;i<n/2;i++)
    {
        if( str[i]!=str[n-i-1] )
        {
            cout<<"Not a palindrome\n";
            x=0;
        }
    }
    if( x==1 )
        cout<<"It is a palindrome\n";
    return 0;
}