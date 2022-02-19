#include<bits/stdc++.h>
using namespace std;

float findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n=A.size(),m=B.size();
    if( n>m )
        return findMedianSortedArrays(B,A);
    
    int start=0,end=n,Mmid=(n+m+1)/2;
    
    while( start<=end )
    {
        int mid=(start+end)/2;
        int leftAsize=mid;
        int leftBsize=Mmid-mid;
        
        int leftA=(leftAsize>0) ? A[leftAsize-1]:INT_MIN;
        int leftB=(leftBsize>0) ? B[leftBsize-1]:INT_MIN;
        int rightA=(leftAsize<n) ? A[leftAsize]:INT_MAX;
        int rightB=(leftBsize<m) ? B[leftBsize]:INT_MAX;
        
        if( leftA<=rightB && leftB<=rightA )
        {
            if( (m+n)%2==0 )
                return (max(leftA,leftB)+min(rightA,rightB))/2;
            
            return max(leftA,leftB);
        }
        else if( leftA>rightB )
            end=mid-1;
        
        else
            start=mid+1;
    }
    return 0;
}

int main()
{
    vector<int> A{1,2};
    vector<int> B{3,4};
    float res=findMedianSortedArrays(A,B);
    cout<<"Median is "<<res<<"\n";
    return 0;
}