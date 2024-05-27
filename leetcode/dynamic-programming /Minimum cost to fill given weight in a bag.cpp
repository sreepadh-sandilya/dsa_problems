class Solution {
  public:
    long long solve(int &n, int &w, vector<int> &cost,vector<vector<long long>>&dp,int i,int sum)
    {
        if(sum==w)
        {
            return 0;
        }
        if(i==n || sum>w)
        {
            return INT_MAX;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        long long take=0,nottake=0;
        if(cost[i]!=-1)
        {
            take=cost[i]+solve(n,w,cost,dp,i,sum+i+1);
        }
        nottake=solve(n,w,cost,dp,i+1,sum);
        
        return dp[i][sum]=min(take,nottake);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<long long>>dp(n+2,vector<long long>(w+2,-1));
        long long ans= solve(n,w,cost,dp,0,0);
        if(ans>=INT_MAX || ans==0)
        {
            return -1;
        }
        return ans;
    }
};
