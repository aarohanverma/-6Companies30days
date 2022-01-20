// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        for(int i=0;i<n;)
        {
            if(arr[i] != i+1 && arr[i] != arr[arr[i] -1])
            {
                swap(arr[i],arr[arr[i] - 1]);
            }
            else
            {
               i++;
            }
        }
        int *arr2 = new int(2);
        for(int i=0;i<n;i++)
        {
            if(arr[i] != i+1)
            {
              arr2[0] = arr[i];
              arr2[1] = i+1;
            }
      }
      return arr2;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
