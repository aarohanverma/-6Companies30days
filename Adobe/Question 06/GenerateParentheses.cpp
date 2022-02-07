// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void helper(int n,vector<string> &res,int l,int r,string str)
    {
        if(str.size()==2*n)
        {
            res.push_back(str);
            return;
        }
        if(r>0 && r>l)
        {
            helper(n,res,l,r-1,str+")");
        }
        if(l>0)
        {
            helper(n,res,l-1,r,str+"(");
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        helper(n,res,n-1,n,"(");
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
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
