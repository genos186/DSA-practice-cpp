#include<bits/stdc++.h>
using namespace std;

/*
string longest(string inp)
{
    int maxlen=1,start=0;
    for(int i=0;i<inp.length();i++)
    {
        for(int j=i;j<inp.length();j++)
        {
            int flag=1;
            for(int k=0;k<(j-i+1)/2;k++)
            {
                if( inp[k+i]!=inp[j-k])
                {
                    flag=0;
                }
            }

            if( flag && (j-i+1)>maxlen )
            {
                start=i;
                maxlen=j-i+1;
            }
        }
    }
    
    string res="";
    for(int i=start;i<start+maxlen;i++)
    {
        res+=inp[i];
    }
    return res;
} */
string longest(string s) {
    int n=s.size();
    int maxl=1;
    int low,high,start;
    
    for(int i=1;i<n;++i)
    {
        //even length plaindrome
        low=i-1;
        high=i;
        while( s[low]==s[high] && low>=0 && high<n )
        {
            --low;
            ++high;
        }
        
        ++low;
        --high;
        if( s[low]==s[high] && maxl<high-low+1 )
        {
            start=low;
            maxl=high-low+1;
        }
        
        //odd length plaindrome
        low=i-1;
        high=i+1;
        while( s[low]==s[high] && low>=0 && high<n )
        {
            --low;
            ++high;
        }
        
        ++low;
        --high;
        if( s[low]==s[high] && maxl<high-low+1 )
        {
            start=low;
            maxl=high-low+1;
        }
    }
    string res="";
    for(int i=start;i<start+maxl;i++)
    {
        res=res+s[i];
    }
    return res;
}

int main()
{
    string inp="udduffddggddffxdx";
    string res=longest(inp);
    cout<<res<<","<<res.size()<<endl;
    return 0;
}