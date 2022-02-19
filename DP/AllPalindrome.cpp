#include<bits/stdc++.h>
using namespace std;

//all possible palindromic partition of a given string
bool isPalindrome( string s,int low,int high )
{
    while( low<high )
    {
        if( s[low]!=s[high] )
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
    
void genPal( vector<vector<string>> &res,vector<string> &cur,int start,int n,string s)
{
    if( start>=n )
    {
        res.push_back(cur);
        return;
    }
    
    for(int i=start;i<n;i++)
    {
        if( isPalindrome(s,start,i) )
        {
            cur.push_back(s.substr(start,i-start+1));
            genPal(res,cur,i+1,n,s);
            cur.pop_back();
        }
    }    
}
    
vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> res;
    vector<string> cur;
    int n=S.length();
    genPal(res,cur,0,n,S);
    return res;
}

int main()
{
    string str="madam";
    vector<vector<string>> res=allPalindromicPerms(str);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}