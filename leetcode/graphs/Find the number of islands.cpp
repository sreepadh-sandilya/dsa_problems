class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&vis,int &n,int &m,int row,int col)
    {
        vector<int>x={0,0,1,-1,1,-1,1,-1};
        vector<int>y={1,-1,0,0,1,-1,-1,1};
        for(int i=0;i<8;i++)
        {
            int newrow=x[i]+row;
            int newcol=y[i]+col;
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m)
            {
                if(grid[newrow][newcol]=='1' && !vis[newrow][newcol])
                {
                    vis[newrow][newcol]=true;
                    dfs(grid,vis,n,m,newrow,newcol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    vis[i][j]=true;
                    count++;
                    dfs(grid,vis,n,m,i,j);
                }
            }
        }
        return count;
    }
};
