class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>& tri,int n,int i,int j)
    {
        if(i>=n || j>=tri[i].size())
        {
            return INT_MAX-10001;
        }
        if(i==n-1)
        {
            return tri[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        ans=min(tri[i][j]+solve(dp,tri,n,i+1,j),tri[i][j]+solve(dp,tri,n,i+1,j+1));
        dp[i][j]=ans;
        return ans;



    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(dp,tri,n,0,0);
        
    }
};
