// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int check(vector<vector<int>> &mat,int val,int x,int y)
    {
        int a=3*(x/3);
        int b=3*(y/3);
        for(int i=a;i<a+3;i++)
        {
            for(int j=b;j<b+3;j++)
            {
                if(i!=x || j!=y)
                {
                    if(mat[i][j]==val)
                    {
                        return 0;
                    }
                }
            }
        }
        
        for(int i=0;i<9;i++)
        {
            if(i==x)
            {
                continue;
            }
            if(mat[i][y]==val)
            {
                return 0;
            }
        }
        
        for(int i=0;i<9;i++)
        {
            if(i==y)
            {
                continue;
            }
            if(mat[x][i]==val)
            {
                return 0;
            }
        }
        return 1;
    }
    int isValid(vector<vector<int>> mat){
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]!=0)
                {
                    if(check(mat,mat[i][j],i,j)==0)
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
