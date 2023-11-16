class Solution {
  public:
    int mod=1e9+7;
    int solve(vector<vector<int>>&dp,vector<int>& arr,int d,int sum,int i,int s,int n,int sz)
    {
        if(i==n)
        {
            if(s == (sum - s) - d)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][s]!=-1)
        {
            return dp[i][s];
        }

        
        int take=solve(dp,arr,d,sum,i+1,s+arr[i],n,sz+1);
        int nottake=solve(dp,arr,d,sum,i+1,s,n,sz);
        dp[i][s]=(take+nottake)%mod;
        return dp[i][s];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(auto i:arr)
        {
            sum+=i;
        }
        if (sum - d < 0 || (sum - d) % 2 != 0) {
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(dp,arr,d,sum,0,0,n,0);
    }
};
