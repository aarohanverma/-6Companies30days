class Solution {
public:
    int dp[501][501];
    
     bool solve(int i,int j,vector<int>&piles,bool turn)
     {
         if(i>j)
         {
            
             return 0;
         }
         if(dp[i][j]!=-1)
         {
             return dp[i][j];
             
         }
        
 
         if(turn ==1)
         {
              dp[i][j]= max(piles[i]+solve(i+1,j,piles,0),piles[j]+solve(i,j-1,piles,0));
         }
         else
         {
             dp[i][j]= min(-piles[i]+solve(i+1,j,piles,1),-piles[j]+solve(i,j-1,piles,1));
         }
         return dp[i][j];
         
     }
    
    
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        for(int i=0;i<501;i++)
        {
            for(int j=0;j<501;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(0,n-1,piles,1);
        
    }
};
