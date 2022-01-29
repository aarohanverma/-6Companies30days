class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_map<string,int> m;
        set<string> s1;
        set<string> s2;
        int c1=0;
        int rows=grid.size();
        int cols=grid[0].size();
        bool flag=false;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]!=0)
                {
                    string temp=to_string(i)+to_string(j);
                    m[temp]=grid[i][j];
                    flag=true;
                    if(grid[i][j]==2)
                    {
                        s1.insert(temp);
                    }
                    else
                    {
                        c1++;
                    }
                }
            }
        }
        if(flag==false)
        {
            return 0;
        }
        int count=-1;
        while(!s1.empty())
        {
            count++;
            for(string x:s1)
            {
                int i=int(x[0]-'0');
                int j=int(x[1]-'0');
                string temp;
                if(i-1>=0)
                {
                    temp=to_string(i-1)+to_string(j);
                    if(m[temp]==1)
                    {
                        m[temp]=2;
                        s2.insert(temp);
                        c1--;
                    }
                }
                
                if(i+1<rows)
                {
                    temp=to_string(i+1)+to_string(j);
                    if(m[temp]==1)
                    {
                        m[temp]=2;
                        s2.insert(temp);
                        c1--;
                    }
                }
                
                if(j-1>=0)
                {
                    temp=to_string(i)+to_string(j-1);
                    if(m[temp]==1)
                    {
                        m[temp]=2;
                        s2.insert(temp);
                        c1--;
                    }
                }
                
                if(j+1<cols)
                {
                    temp=to_string(i)+to_string(j+1);
                    if(m[temp]==1)
                    {
                        m[temp]=2;
                        s2.insert(temp);
                        c1--;
                    }
                }
                
            }
            s1.clear();
            s1.swap(s2);
            s2.clear();
        }
        if(c1!=0)
        {
            return -1;
        }
        return count;
    }
};
