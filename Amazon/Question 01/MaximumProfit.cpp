// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        int profit[K + 1][N + 1];
 
        for (int i = 0; i <= K; i++)
        {
            profit[i][0] = 0;
        }
 
        for (int j = 0; j <= N; j++)
        {
            profit[0][j] = 0;
        }
 
    for (int i = 1; i <= K; i++) 
    {
        int prevDiff = INT_MIN;
        for (int j = 1; j < N; j++) 
        {
            prevDiff = max(prevDiff,profit[i - 1][j - 1] - A[j - 1]);
            profit[i][j] = max(profit[i][j - 1],A[j] + prevDiff);
        }
    }
 
    return profit[K][N - 1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
