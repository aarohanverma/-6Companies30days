// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int res=0;
        bool neg=false;
        for(int i=str.size()-1;i>=0;i--)
        {
            if(isalpha(str[i]))
            {
                return -1;
            }
            if(str[i]=='-')
            {
                neg=true;
                break;
            }
            res=res+pow(10,str.size()-1-i)*int(str[i]-'0');
        }
        if(neg==true)
        {
            return -res;
        }
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
