#include<bits/stdc++.h>
using namespace std;

int ladderLen(string beginWord,string endWord,vector<string> wordList)
{
    unordered_set<string> myset;
    bool isPresent=false;
    
    for(auto word:wordList)
    {
        if( endWord.compare(word)==0 )
        {
            isPresent=true;
        }
        myset.insert(word);
    }
    if( isPresent==false )
        return 0;
    
    queue<string> q;
    q.push(beginWord);
    int depth=0;
    
    while( !q.empty() )
    {
        depth+=1;
        int lsize=q.size();
        while( lsize-- )
        {
            string cur=q.front();
            q.pop();
            
            for(int i=0;i<cur.length();i++)
            {
                string temp=cur;
                for(char c='a';c<='z';c++)
                {
                    temp[i]=c;
                    if( cur.compare(temp)==0 )
                        continue;
                    if( temp.compare(endWord)==0 )
                        return depth+1;
                    if( myset.find(temp)!=myset.end() )
                    {
                        q.push(temp);
                        myset.erase(temp);
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    string beg="hit";
    string end="cog";
    vector<string> words{"hot","dot","dog","lot","log","cog"};
    int res=ladderLen(beg,end,words);
    cout<<res<<"\n";
    return 0;
}