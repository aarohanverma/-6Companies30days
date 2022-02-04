// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n==1) 
        {
            return arr[0];
        }
        if(n==2)  
        {
            return max(arr[0],arr[1]);
        }
        int A[n+1]; // dp array
        A[0]=0;
        A[1]=arr[0];
        for (int i = 2; i <=n; i++)
        {
            A[i]=max(arr[i-1]+A[i-2],A[i-1]);
        }
        return A[n]; //maximum loot...
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
