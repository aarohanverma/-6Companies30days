// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>& A,int i,int j)
    {
        if(i==j)
        {
            return A[i];
        }
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }    
   
        int left = A[i] + min(solve(A,i+2,j),solve(A,i+1,j-1));
        int right = A[j] + min(solve(A,i,j-2),solve(A,i+1,j-1));
   
        return dp[i][j] = max(left,right);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    memset(dp,-1,sizeof(dp));
        return solve(A,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
