class Solution {
public:
    const int mod = 1000000007;
    int solve(int &n,int i,int a,int l,vector<vector<vector<int>>>&dp)
    {
        if(a>=2)
        {
            return 0;
        }
        if(l>=3)
        {
            return 0;
        }
        if(i==n)
        {
            return 1;
        }
        if(dp[i][a][l]!=-1)
        {
            return dp[i][a][l];
        }
        int x=solve(n,i+1,a+1,0,dp);
        int y=solve(n,i+1,a,l+1,dp);
        int z=solve(n,i+1,a,0,dp);
        return dp[i][a][l]=(x+(y+z)%mod)%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,0,0,0,dp);
    }
};
