// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n==1)
        {
            return 1;
        }
        int mat[n][n];
        unordered_map<int,bool> s;
        for(int i=0;i<n;i++)
        {
            s[A[i]]=true;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mat[i][j]=A[j]-A[i];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=A[j];
                int count=1;
                while(s.find(x+mat[i][j])!=s.end())
                {
                    count++;
                    x=x+mat[i][j];
                }
                ans=max(ans,count);
            }
        }
        return ans+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
