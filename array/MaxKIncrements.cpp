#include<bits/stdc++.h>
using namespace std;

void findMostFrequent(int arr[], int N,int K)
{
    int start = 0, end = 0;

    sort(arr, arr + N);
  
    int mostFreq = INT_MIN, sum = 0;

    for (end = 0; end < N; end++) {
  
        sum = sum + arr[end];

        while (sum + K < arr[end] * (end - start + 1)) {
            sum = sum - arr[start];
            start++;
        }

        mostFreq = max(mostFreq,end - start + 1);
    }

    int reqSum = arr[N - 1] * N - sum;

    if (mostFreq == N && reqSum < K) {
        K = K - reqSum;

        if (K % N == 0) {
            cout << N << endl;
        }
        else {
            cout << N - 1 << endl;
        }
  
        return;
    }
    cout << mostFreq << endl;
}
  
int main()
{
    int arr[] = { 1, 3, 2, 2 };
    int K = 2;
    int N = sizeof(arr) / sizeof(arr[0]);
    findMostFrequent(arr, N, K);
  
    return 0;
}