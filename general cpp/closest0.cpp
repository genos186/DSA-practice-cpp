#include<bits/stdc++.h>
using namespace std;

int Solve (int N, vector <int> A) {
   // Write your code
   int m=A[0]; 
   if(m<0)
   {
       m=m*(-1);
   }

   for(int i=1;i<N;i++)
   {
       if( A[i]<0 )
       {
           if( m<0 )
           {
               int t1=A[i]*(-1);
               int t2=m*(-1);
                if( t1<t2 )
                {
                    m=A[i];
                }
           }
           else
           {
               int t=A[i]*(-1);
                if( t<m )
                {
                    m=A[i];
                }
           }       
       }
       else  
       {
           if( m<0 )
           {
               int t=m*(-1);
                if( A[i]<t )
                {
                    m=A[i];
                }
           }
           else
           {
                if( A[i]<m )
                {
                    m=A[i];
                }
           }    
       }

   }
   return m;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N=100;
    vector <int> A={-99 ,-49, 99, -98 ,98 ,-97 ,97 ,-96 ,96 ,-95, 95 ,-94 ,94 ,-93 ,93 ,-92 ,92 ,-91 ,91, -90 ,90 ,-89, 89, -88 ,88 ,-87, 87 ,-86, 86 ,-85 ,85 ,-84, 84, -83 ,83, -82 ,82 ,-81, 81 ,-80, 80, -79 ,79, -78, 78 ,-77, 77, -76, 76, -75, 75 ,-74, 74, -73, 73 ,-72 ,72, -71, 71, -70, 70, -69, 69, -68, 68, -67, 67, -66, 66 ,-65, 65 ,-64 ,64 ,-63, 63, -62, 62, -61, 61, -60, 60, -59, 59 ,-58, 58, -57, 57, -56, 56, -55 ,55, -54 ,54 ,-53 ,53 ,-52, 52 ,-51, 51, -50, 50};
    int out = Solve(N, A);
    cout << out << "\n";
}

