/*
#include<bits/stdc++.h>
using namespace std;

void findsplit( int a[],int n )
{
    int S=0;
    vector<int> res;
    for( int i=0;i<n;i++ )
    {
        S+=a[i];
    }
	cout<<"Tsum="<<S<<'\n';
    if( S%3!=0 )
    {
        return;
    }
    int S3=S/3;
	cout<<"Sum of 1/3rd="<<S3<<endl;
    int pre=0,count=0;
    for( int j=0;j<n;j++ )
    {
        if( pre<S3 )
        {
            pre+=a[j];
			count++;
        }
        if( pre==S3 )
        {
            res.push_back(count);
			count=0;
            pre=0;
        }
    }
    int k=1;
	for(int p=0;p<res.size();p++)
	{
		cout<<res[p]<<" ";
	}
	cout<<endl;
    while( k<res.size() )
    {
        for(int x=0;x<=res[k];x++)
        {
            cout<<a[x]<<" ";
        }
        cout<<endl;
        k+=res[k];
    }
}

int main()
{
    int a[]={4,1,0,3,4};
    int n=sizeof(a)/sizeof(0);
    findsplit(a,n);
    
    return 0;
}
*/
// ----------------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

// First segment's end index
static int pos1 = -1;

// Third segment's start index
static int pos2 = -1;

// This function returns true if the array
// can be divided into three equal sum segments
bool equiSumUtil(int arr[],int n)
{

	// Prefix Sum Array
	int pre[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		pre[i] = sum;
	}
	for(int x=0;x<n;x++)
	{
		cout<<pre[x]<<" ";
	}
	cout<<endl;
	// Suffix Sum Array
	int suf[n];
	sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sum += arr[i];
		suf[i] = sum;
	}

	for(int x=0;x<n;x++)
	{
		cout<<suf[x]<<" ";
	}
	cout<<endl;
	// Stores the total sum of the array
	int total_sum = sum;

	int i = 0, j = n - 1;
	while (i < j - 1)
	{

		if (pre[i] == total_sum / 3)
		{
				pos1 = i;
		}

		if (suf[j] == total_sum / 3)
		{
			pos2 = j;
		}

		if (pos1 != -1 && pos2 != -1)
		{

			// We can also take pre[pos2 - 1] - pre[pos1] ==
			// total_sum / 3 here.
			if (suf[pos1 + 1] - suf[pos2] == total_sum / 3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (pre[i] < suf[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	return false;
}

void equiSum(int arr[],int n)
{
	bool ans = equiSumUtil(arr,n);
	if (ans)
	{

		cout << "First Segment : ";
		for (int i = 0; i <= pos1; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;

		cout << "Second Segment : ";
		for (int i = pos1 + 1; i < pos2; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;

		cout << "Third Segment : ";
		for (int i = pos2; i < n; i++)
		{
			cout << arr[i] << " ";
		}

		cout<<endl;
	}
	else
	{
		cout << "Array cannot be divided into three equal sum segments";
	}
}

int main()
{
	int arr[] = {4,1,0,3,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	equiSum(arr,n);
	return 0;
}

