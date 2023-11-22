
class Solution {
public:
    int solve(vector<int>& prices,vector<vector<vector<int>>>&dp,int &n,int i,int buy,int sum,int &k)
    {
       if(i==n)
       {
           return 0;
       }
       if(sum==k)
       {
           return 0;
       }
       if(dp[i][buy][sum]!=-1)
       {
           return dp[i][buy][sum];
       }
       if(buy)
       {
           return dp[i][buy][sum]=max(-prices[i]+solve(prices,dp,n,i+1,0,sum,k),solve(prices,dp,n,i+1,1,sum,k));
       }
       else
       {
           return dp[i][buy][sum]=max(prices[i]+solve(prices,dp,n,i+1,1,sum+1,k),solve(prices,dp,n,i+1,0,sum,k));
       }
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));
        int p=solve(prices,dp,n,0,1,0,k);
        if(p<0)
        {
            return 0;
        }
        return p;
        
    }
};
