// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    
	    int count(string str,int sz,unordered_map<int,int> &m)
	    {
	        if(sz==0 || sz==1)
	        {
	            return 1;
	        }

	        if(m.find(sz)!=m.end())
	        {
	            return m[sz]%1000000007;
	        }
	        int counter=0;
	        if(str[sz-1]>'0')
	        {
	            counter=count(str.substr(0,sz-1),sz-1,m)%1000000007;
	        }
	        if (str[sz - 2] == '1'  || (str[sz - 2] == '2' && str[sz - 1] < '7'))
	        {
                counter=counter + count(str.substr(0,sz-1), sz - 2,m)%1000000007;
	        }
	        return m[sz]=counter%1000000007;
	    }
		int CountWays(string str){
		    unordered_map<int,int> m;
		    int sz=str.size();
		    if (sz == 0 || str[0] == '0')
		    {
                return 0;
		    }
		    for(int i=0;i<sz-1;i++)
		    {
		        if(str[i]=='0' && str[i+1]=='0')
		        {
		            return 0;
		        }
		    }
		    return count(str,sz,m);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
