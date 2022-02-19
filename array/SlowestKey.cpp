#include<bits/stdc++.h>
using namespace std;

char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    map<char,int> dic;
    dic[keysPressed[0]]=releaseTimes[0];
    for(int i=1;i<keysPressed.length();i++)
    {
        int diff=releaseTimes[i]-releaseTimes[i-1];
        dic[keysPressed[i]]+=diff;
    }
    
    map<char,int>::iterator itr;
    for(itr=dic.begin();itr!=dic.end();itr++)
        cout<<"("<<itr->first<<"-"<<itr->second<<")";
    cout<<"\n";

    int m=INT_MIN;
    for(itr=dic.begin();itr!=dic.end();itr++)
    {
        if( m<itr->second )
            m=itr->second;
    }
    for(itr=dic.begin();itr!=dic.end();itr++)
    {
        if( m==itr->second )
            return itr->first;
    }
    return 0;
}

int main()
{
    vector<int> time{1,2};
    string str="ba";
    char res=slowestKey(time,str);
    cout<<res<<"\n";
    return 0;
}
