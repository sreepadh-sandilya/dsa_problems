class Solution
{
    public:
    int mod=1e9+7;
    int solve(string &s, string &t,vector<vector<int>>&dp,int i,int j,int &n,int &m)
    {
        if(j==m)
        {
            return 1;
        }
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j]%mod;
        }
        if(s[i]==t[j])
        {
            int l=solve(s,t,dp,i+1,j,n,m);
            int ta=solve(s,t,dp,i+1,j+1,n,m);
            return dp[i][j]=(l+ta)%mod;
        }
        else
        {
            return dp[i][j]=solve(s,t,dp,i+1,j,n,m)%mod;
        }
        
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      
      int n=s.length();
      int m=t.length();
      if(m>n)
      {
          return 0;
      }
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return solve(s,t,dp,0,0,n,m)%mod;
      
    }
};
 
