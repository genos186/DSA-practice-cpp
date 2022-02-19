#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{3,6,1,8,5,4,9};

    int first=0,second=-1;

    for(int i=1;i<a.size();i++)
    {
        if( a[i]>a[first] )
        {
            second=first;
            first=i;
        }
        else if( a[i]<a[first] )
        {
            if( second==-1 || a[i]>a[second] )
                second=i;
        }
    }
    cout<<"Second largest element "<<a[second]<<"\n";
    return 0;
}