class Solution {
  public:
    int mod= 1e9+7;
    int solve(int &n,int i,int flag,int dig,vector<vector<vector<int>>>&dp)
    {
        if(i==n-1)
        {
            if(flag){
            return 1;
            }
            else
            {
                return 0;            
                
            }
        }
        if(dp[i+1][flag][dig]!=-1)
        {
            return dp[i+1][flag][dig];
        }
        if(i==-1)
        {
            return dp[i+1][flag][dig]= (solve(n,i+1,0,0,dp)+solve(n,i+1,0,1,dp))%mod;
        }
        else
        {
            if(flag==1)
            {
                return dp[i+1][flag][dig]= (solve(n,i+1,1,0,dp)+solve(n,i+1,1,1,dp))%mod;
            }
            else{
                if(dig==0)
                {
                    return dp[i+1][flag][dig]= (solve(n,i+1,0,0,dp)+solve(n,i+1,0,1,dp))%mod;
                }
                else
                {
                    return dp[i+1][flag][dig]= (solve(n,i+1,0,0,dp)+solve(n,i+1,1,1,dp))%mod;
                }
            }
        }
    }
    int numberOfConsecutiveOnes(int n) {
        // code here
        vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(n,-1,0,0,dp);
    }
};
