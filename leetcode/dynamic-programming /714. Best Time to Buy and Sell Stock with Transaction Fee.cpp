class Solution {
public:
    int solve(vector<int>& prices,vector<vector<int>>&dp,int &n,int i,int buy,int &fee)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][buy]!=INT_MIN)
        {
            return dp[i][buy];
        }
        if(buy)
        {
            dp[i][buy]=  max(solve(prices,dp,n,i+1,1,fee),-prices[i]+solve(prices,dp,n,i+1,0,fee));
            return dp[i][buy];
        }
        else
        {
            dp[i][buy]=max(prices[i]+solve(prices,dp,n,i+1,1,fee)-fee,solve(prices,dp,n,i+1,0,fee));
            return dp[i][buy];
        }
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        return solve(prices,dp,n,0,1,fee);


    }
};
