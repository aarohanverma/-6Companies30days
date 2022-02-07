// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        int half=N.size()/2;
        string first_half=N.substr(0,half);
        bool flag=next_permutation(first_half.begin(),first_half.end());
        if(flag==false)
        {
            return "-1";
        }
        string temp=first_half;
        reverse(temp.begin(),temp.end());
        if(N.size()%2==0)
        {
            return first_half+temp; 
        }
        else
        {
            return first_half+N[half]+temp;
        }
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
