#include<bits/stdc++.h>
using namespace std;

void StockSpan(int price[],int n)
{
    vector <int> span_val;
    stack <int> temp;
    
    span_val.emplace_back(1);
    temp.push(0);
    
    for(int i=1;i<n;i++)
    {
        while( !(temp.empty()) && (price[temp.top()]<=price[i]) )
        {
            temp.pop();
        }
        
        if( temp.empty() )
            span_val.emplace_back(i+1);
        else
            span_val.emplace_back(i-temp.top());
        temp.push(i);
    }

    for(int j=0;j<n;j++)
    {
        cout<<span_val[j]<<" ";
    }
    cout<<endl;
}

int main()
{
    int price[]={100,80,60,70,60,75,85,60,120};
    int n=sizeof(price)/sizeof(0);
    StockSpan(price,n);
    return 0;
}