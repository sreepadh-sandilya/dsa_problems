class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<int>& prices,int &n,int i,int j)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j+1]!=-1)
        {
            return dp[i][j+1];
        }
        
        if(i<=j)
        {
            return dp[i][j+1]=min(prices[i]+solve(dp,prices,n,i+1,i+i+1),solve(dp,prices,n,i+1,j));
        }
        else
        {
            return dp[i][j+1]=prices[i]+solve(dp,prices,n,i+1,i+i+1);
        }
        
           
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*n+1,-1));
        return solve(dp,prices,n,0,-1);
        
        
    }
};
