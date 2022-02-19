#include<bits/stdc++.h>
using namespace std;

int main()
{
    int start[]={1,3,0,5,8,5};
    int end[]={2,4,6,7,9,9};

    int n=sizeof(start)/sizeof(0);

    multimap< int,int > meetings;


    multimap< int,int >::iterator itr1;
    multimap< int,int >::iterator itr2;
    for(int i=0;i<n;i++)
    {
        meetings.emplace(end[i],start[i]);
    }
    //printing all meetings
    cout<<"{";
    for( itr1=meetings.begin(); itr1!=meetings.end(); itr1++ )
    {
        cout<<"("<<itr1->second<<","<<itr1->first<<")";
    }
    cout<<"}";
    cout<<"\n";

    int count=1;
    itr1=meetings.begin();
    cout<<"("<<itr1->second<<","<<itr1->first<<")\t";

    for(itr2=std::next(meetings.begin()); itr2!=meetings.end(); itr2++)
    {
        if( itr2->second >= itr1->first )
        {
            count++;
            cout<<"("<<itr2->second<<","<<itr2->first<<")\t";
            itr1=itr2;
        }
    }
    
   /*
    multimap< int,int >::iterator itr;
    for(int i=0;i<n;i++)
    {
        meetings.emplace(start[i],end[i]);
    }
        
    int count=1;
    int j=0;
    itr=meetings.begin();
    while( j<n && itr!=meetings.end() )
    {
        start[j]=itr->first;
        end[j]=itr->second;
        j++;
        itr++;
    }

    for(int x=0;x<n;x++)
    {
        cout<<start[x]<<","<<end[x]<<"\t";
    }
    cout<<"\n";
    j=0;
        
    for(int k=1;k<n;k++)
    {
        if( start[k] >= end[j] )
        {
            count+=1;
            j=k;
        }
    } */
    cout<<endl<<count;
    return 0;
}