class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>& matrix,int m,int n,int i,int j)
    {
        if(i>=m || j>=n || j<0)
        {
            return INT_MAX-101;
        }
        if(dp[i][j]!=INT_MIN)
        {
            return dp[i][j];
        }
        if(i==m-1)
        {
            return matrix[i][j];
        }
        int ans=INT_MAX;
  
        // int ans = INT_MAX - 101;
        int a=matrix[i][j] + solve(dp, matrix, m, n, i + 1, j - 1);
        int b=matrix[i][j] + solve(dp, matrix, m, n, i + 1, j);
        int c=matrix[i][j] + solve(dp, matrix, m, n, i + 1, j + 1);

        // ans = min(ans, matrix[i][j] + solve(dp, matrix, m, n, i + 1, j - 1));
        // ans = min(ans, matrix[i][j] + solve(dp, matrix, m, n, i + 1, j));
        // ans = min(ans, matrix[i][j] + solve(dp, matrix, m, n, i + 1, j + 1));
        return dp[i][j]=min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MIN));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
        ans=min(ans, solve(dp,matrix,m,n,0,i));
        }
        return ans;

        
    }
};

