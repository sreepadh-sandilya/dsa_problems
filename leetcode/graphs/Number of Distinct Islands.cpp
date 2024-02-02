class Solution {
  public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,vector<pair<int,int>>&v,int &m,int &n,int row,int col,int row0,int col0)
    {
        if(row>=n || row<0 || col>=m || col<0)
        {
            return;
        }
        if(grid[row][col]==1 && !vis[row][col])
        {
            vis[row][col]=true;
            v.push_back({row-row0,col-col0});
            vector<int>x={0,1,-1,0};
            vector<int>y={1,0,0,-1};
            for(int i=0;i<4;i++)
            {
                int a=x[i]+row,b=y[i]+col;
                if(a>=0 && a<n && b>=0 && b<m)
                {
                    dfs(grid,vis,v,m,n,a,b,row0,col0);
                }
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>v;
                    dfs(grid,vis,v,m,n,i,j,i,j);
                    // sort(v.begin(),v.end());
                    st.insert(v);
                }
            }
        }
        
        return st.size();
    }
};
