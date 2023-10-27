class Solution {
public:
    int solve1(int n,vector<int>&cost)
    {
        vector<int>dp(n+1);
        if(n==0 || n==1)
        {
            return dp[n];
        }
        dp[0]=cost[0];
        dp[1]=cost[1];
        

        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
    int solve(int n,vector<int>&cost,vector<int>&dp)
    {
        if(n==0 || n==1)
        {
            return cost[n];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=min(solve(n-1,cost,dp),solve(n-2,cost,dp))+cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        
        // return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        return solve1(n,cost);
        
    }
};
