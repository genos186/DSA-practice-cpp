#include<bits/stdc++.h>
using namespace std;

//convertion of data type
int main()
{
    //integer to string
    int len=52;
    string str="abcde fgh";
    string x=to_string(len);
    for(int i=0;i<str.length();i++)
    {
        if( str[i]==' ' )
        {
            string temp=to_string(len);
            str.replace(i,temp.length(),temp);
            //str[i]=temp;
        }
    }
    cout<<str<<"\n";
    //string to integer
    string str1 = "-45";
    string str2 = "3.14159";
    string str3 = "31337 nerd";
 
    cout<<stoi(str1)<<"\n";
    cout<<stoi(str2)<<"\n";
    cout<<stoi(str3)<<"\n";

    return 0;
}
