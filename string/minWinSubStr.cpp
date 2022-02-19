#include<bits/stdc++.h>
using namespace std;
/* Brute Force
string minWindow(string s, string t) {
    vector<string> comb;
    
    if( t.length()>s.length() )
    {
        return "";
    }
    if( t.length()==s.length() )
    {
        if( s.compare(t)==0 )
        {
            return s;
        } 
        else
        {
            return "";
        }
    }
    
    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j<s.length();j++)
        {
            if( j-i<t.length() )
                continue;
            else
            {
                string str=s.substr(i,j-i+1);
                comb.push_back(str);
            }
        }
    }

    for(auto itr:comb)
    {
        cout<<itr<<" ";
    }
    cout<<"\n";

    int mlen=comb[0].size();
    int pos=0,x;
    for(int i=0;i<comb.size();i++)
    {
        x=0;
        for(int j=0;j<t.size();j++)
        {
            for(int k=0;k<comb[i].size();k++)
            {
                if( t[j]==comb[i][k] )
                {
                    x+=1;
                    break;
                }
            }
        }
        if( x==t.length() && mlen>=comb[i].size() )
            {
                mlen=comb[i].size();
                pos=i;
            }
    }
    return comb[pos];
}
*/
string minWindow(string s, string t) {
    int m[256] = { 0 };
    int ans = INT_MAX;
    int start = 0; 
    int count = 0;

    // creating map
    for (int i = 0; i < t.length(); i++) {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    // References of Window
    int i = 0;
    int j = 0;

    // Traversing the window
    while (j < s.length()) {
    
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        // Condition matching
        if (count == 0) {
            while (count == 0) {
                // Sorting ans
                if (ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I

                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }

    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "";
}

int main()
{
    string s="abcde";
    string t="ac";
    cout<<minWindow(s,t)<<"\n";
    return 0;
}