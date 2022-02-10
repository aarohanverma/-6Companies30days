class Solution 
{
    public:
    int numberOfBoomerangs(vector<vector<int>>& p)
    {
        int ans=0;
        int n=p.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> mp;
            for (int j =0; j <n; ++j)
            {
                int dx=abs(p[i][0]-p[j][0]);
                int dy=abs(p[i][1]-p[j][1]);
                int d=dx*dx+dy*dy;
                ans+=(2*mp[d]);
                mp[d]++;
            }
        }
        return ans;
    }
};
