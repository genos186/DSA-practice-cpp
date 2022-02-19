#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<char>> &board,string word,int k,int i,int j,int n,int m)
{
    if( i<0 || i>=n || j<0 || j>=m || word[k]!=board[i][j] )
        return false;
    
    if( k==word.size()-1 )
        return true;
    
    char c=board[i][j];
    board[i][j]='*';
    
    bool next= search(board,word,k+1,i+1,j,n,m) || search(board,word,k+1,i-1,j,n,m) || search(board,word,k+1,i,j+1,n,m) || search(board,word,k+1,i,j-1,n,m);
    
    board[i][j]=c;
    return next;
}

bool exist(vector<vector<char>>& board, string word) 
{
    if( word.empty() )
        return true;
    
    if( board.empty() )
        return false;
    
    int n=board.size();
    int m=board[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( search(board,word,0,i,j,n,m))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };
    string word = "ABCCFDEE";
    if( exist(board,word) )
        cout<<"Word exists\n";
    else
        cout<<"Word doesn't exist\n";

    return 0;
}