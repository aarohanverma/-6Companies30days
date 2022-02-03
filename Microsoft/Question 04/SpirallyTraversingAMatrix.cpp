// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
    int lt=0;
    int rt=c;
    int up=0;
    int dn=r;
    vector<int> v;
    while(up<dn && lt<rt)
    {
        int i=lt;
        int j=up;
        for(;i<rt;i++)
        {
            v.push_back(matrix[j][i]);
        }
        rt--;
        i=rt;
        j=up+1;
        
        for(;j<dn;j++)
        {
            v.push_back(matrix[j][i]);
        }
        dn--;
        i=rt-1;
        j=dn;
        
        for(;i>=lt && j>up;i--)
        {
            v.push_back(matrix[j][i]);
        }
        i=lt;
        j=dn-1;
        
        for(;j>up && i<rt;j--)
        {
            v.push_back(matrix[j][i]);
        }
        up++;
        lt++;
           
    }
    return v; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
