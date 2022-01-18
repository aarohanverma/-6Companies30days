// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	     vector <long long int > ug(n+1);
    
     ug[0]=1;
    
   long long int c2(0),c3(0),c5(0);
    
    for(int i=1;i<=n;i++)
    {
        ug[i] =min({2*ug[c2] , 3*ug[c3] , 5*ug[c5]});
        
        if(2*ug[c2]==ug[i])
            c2++;
            
       if(3*ug[c3]==ug[i])
            c3++;
            
       if(5*ug[c5]==ug[i])
            c5++;
    }
    return ug[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
