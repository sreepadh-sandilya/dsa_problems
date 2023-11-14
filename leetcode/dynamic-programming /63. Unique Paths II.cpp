class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>& grid,int m,int n,int i,int j)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];

        }
        int ans=0;
        int a=0,b=0;
        if(i+1<=m-1 && grid[i+1][j]!=1)
        {
           a=solve(dp,grid,m,n,i+1,j);
        }
        if(j+1<=n-1 && grid[i][j+1]!=1)
        {
            b=solve(dp,grid,m,n,i,j+1);
        }
        ans=a+b;
        dp[i][j]=ans;
        return ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
        {
            return 0;
        }
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(dp,grid,m,n,0,0);
        
    }
};
