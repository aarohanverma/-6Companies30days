// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int helper(int i,int j,vector<vector<int>> &m,vector<vector<int>> &grid)
    {

        m[i][j]=1;
        int count=0;
        
        if(i-1>=0 && grid[i-1][j]==1 && m[i-1][j]==0)
        {
            count=count+1+helper(i-1,j,m,grid);
        }
        
        if(i+1<grid.size() && grid[i+1][j]==1 && m[i+1][j]==0)
        {
            count=count+1+helper(i+1,j,m,grid);
        }
        
        if(j-1>=0 && grid[i][j-1]==1 && m[i][j-1]==0)
        {
            count=count+1+helper(i,j-1,m,grid);
        }
        
        if(j+1<grid[0].size() && grid[i][j+1]==1 && m[i][j+1]==0)
        {
            count=count+1+helper(i,j+1,m,grid);
        }
        
        if(i-1>=0 && j+1<grid[0].size() && grid[i-1][j+1]==1 && m[i-1][j+1]==0)
        {
            count=count+1+helper(i-1,j+1,m,grid);
        }
        
        if(i+1<grid.size() && j+1<grid[0].size() && grid[i+1][j+1]==1 && m[i+1][j+1]==0)
        {
            count=count+1+helper(i+1,j+1,m,grid);
        }
        
        if(i+1<grid.size() && j-1>=0 && grid[i+1][j-1]==1 && m[i+1][j-1]==0)
        {
            count=count+1+helper(i+1,j-1,m,grid);
        }
        
        if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==1 && m[i-1][j-1]==0)
        {
            count=count+1+helper(i-1,j-1,m,grid);
        }
        
        return count;
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        vector<vector<int>> m(grid.size(), vector<int>(grid[0].size(), 0));
        int count=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && m[i][j]==0)
                {
                    count=max(count,1+helper(i,j,m,grid));
                }
                
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
