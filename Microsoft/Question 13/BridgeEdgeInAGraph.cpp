// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> vis(V,-1);
        queue<int> q;
        q.push(c);
        vis[c] = 1;
        int count = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto elem : adj[u])
            {
                if(elem == d)
                {
                    count++;
                    if(count>1) return 0;
                    continue;
                }
                else if(vis[elem] == -1)
                {
                    q.push(elem);
                    vis[elem] = 1;
                }
            }
        }
        
        return 1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
