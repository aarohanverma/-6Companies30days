// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        int r_x_max=max(R1[0],R2[0]);
        int r_x_min=min(R1[0],R2[0]);
        int r_y_max=max(R1[1],R2[1]);
        int r_y_min=min(R1[1],R2[1]);
        
        int l_x_max=max(L1[0],L2[0]);
        int l_x_min=min(L1[0],L2[0]);
        int l_y_max=max(L1[1],L2[1]);
        int l_y_min=min(L1[1],L2[1]);
        
        if(l_y_min>=r_y_max &&  r_x_min>=l_x_max)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends
