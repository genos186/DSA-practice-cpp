#include<bits/stdc++.h>
using namespace std;

bool CheckVowel(char ch)
{
    if( ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' )
    {
        return true;
    }
    return false;
}

void LongStrVow(string s)
{
    int Longest,count=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if( CheckVowel(s[i]) )
        {
            count=0;
        }
        else
        {
            count++;
        }
        Longest=max(Longest,count);
    }
    cout<<Longest<<endl;
}

int main()
{
    string s="helloiamfldskjdhf";
    LongStrVow(s);
    return 0;
}