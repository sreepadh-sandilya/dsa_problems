class Solution {
public:
    int solve(vector<int>& prices,vector<vector<vector<int>>>&dp,int &n,int i,int buy,int sum)
    {
       if(i==n)
       {
           return 0;
       }
       if(sum==2)
       {
           return 0;
       }
       if(dp[i][buy][sum]!=-1)
       {
           return dp[i][buy][sum];
       }
       if(buy)
       {
           return dp[i][buy][sum]=max(-prices[i]+solve(prices,dp,n,i+1,0,sum),solve(prices,dp,n,i+1,1,sum));
       }
       else
       {
           return dp[i][buy][sum]=max(prices[i]+solve(prices,dp,n,i+1,1,sum+1),solve(prices,dp,n,i+1,0,sum));
       }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        int k=solve(prices,dp,n,0,1,0);
        if(k<0)
        {
            return 0;
        }
        return k;
        
    }
};
