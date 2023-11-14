class Solution {
public:
    int solve(int m,int n,vector<vector<int>>&dp,vector<vector<int>>& grid,int i,int j)
    {
        if(i>=m || j>=n)
        {
            return INT_MAX-201;
        }
        if(i==m-1 && j==n-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        int a=0,b=0;
        ans=min(grid[i][j]+solve(m,n,dp,grid,i+1,j),grid[i][j]+solve(m,n,dp,grid,i,j+1));

        dp[i][j]=ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m,n,dp,grid,0,0);
        
    }
};

