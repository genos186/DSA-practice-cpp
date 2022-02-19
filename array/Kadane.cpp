#include<bits/stdc++.h>
using namespace std;

//finding maximum sum in the array with O(n) with kadane's algorithm
int main()
{
    vector<int> arr{1,2,-2,-4,6,8,-3,4};
    int mend=0;
    int mfar=INT_MIN;

    for(int i=0;i<arr.size();i++)
    {
        mend=mend+arr[i];
        if( mend>mfar )
        {
            mfar=mend;
        }
        if( mend<0 )
        {
            mend=0;
        }
    }
    cout<<mfar<<"\n";
    return 0;
}