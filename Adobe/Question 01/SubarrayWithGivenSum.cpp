// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        long long curr_sum=arr[0];
        int i=0;
        int j=0;
        vector<int> res;
        while(j<n)
        {
            if(curr_sum==s)
            {
                break;
            }
            else if(curr_sum<s)
            {
                j++;
                if(j<n)
                {
                    curr_sum=curr_sum+arr[j];
                }
            }
            else
            {
                curr_sum=curr_sum-arr[i];
                i++;
            }
        }
        if(j==n)
        {
            res.push_back(-1);
            return res;
        }
        res.push_back(i+1);
        res.push_back(j+1);
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
