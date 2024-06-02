class Solution {
public:
    void dfs(vector<vector<char>>& grid,int &n,int &m,vector<vector<bool>>&vis,int i,int j)
    {
        vis[i][j]=true;
        vector<int>x={0,1,-1,0};
        vector<int>y={1,0,0,-1};
        for(int k=0;k<4;k++)
        {
            int p=i+x[k],q=j+y[k];
            if(p>=n || p<0 || q>=m || q<0)
            {
                continue;
            }
            if(grid[p][q]=='1' && !vis[p][q])
            {
                dfs(grid,n,m,vis,p,q);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]  && grid[i][j]=='1')
                {
                    dfs(grid,n,m,vis,i,j);
                    sum++;
                }
            }
        }
        return sum;
    }
};
