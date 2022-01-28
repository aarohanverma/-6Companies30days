// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int> m;
		    queue<char> q;
		    string res="";
		    for(int i=0;i<26;i++)
		    {
		        m['a'+i]=0;
		    }
		    char x;
		    
		    for(int i=0;i<A.size();i++)
		    {
		        m[A[i]]++;
		        if(m[A[i]]==1)
		        {
		            q.push(A[i]);
    		        x=q.front();
		        }
		        else
		        {
		            while(!q.empty() && m[q.front()]>1)
		            {
		                q.pop();
		            }
		            if(q.empty())
		            {
		                x='#';
		            }
		            else
		            {
		                x=q.front();
		            }
		        }
		        res=res+x;
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
