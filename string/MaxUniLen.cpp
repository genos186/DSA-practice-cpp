#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    map<char,int> dict;
    map<char,int>::iterator itr;
    int uniLen=0;
    //keeping track of the starting point of subarray
    int start=-1;
    
    for(int i=0;i!=s.length();i++)
    {
        if( dict.count(s[i]) )
        {
            start=max(start,dict[s[i]]);
        }
        dict[s[i]]=i;
        uniLen=max(uniLen,i-start);
    }
    //subarray with unique char of max length
    for(itr=dict.begin();itr!=dict.end();itr++)
    {
        cout<<itr->first;
    }
    //cout<<"\n"<<start;
    cout<<endl;
    return uniLen;
}

int main()
{
    string inpu="abcabbbabcdea";
    int res=lengthOfLongestSubstring(inpu);
    cout<<res<<endl;
    return 0;
}