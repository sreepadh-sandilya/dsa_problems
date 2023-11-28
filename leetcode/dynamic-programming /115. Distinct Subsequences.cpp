class Solution {
public:
    int solve(vector<vector<int>>&dp,string &s, string &t,int &m,int &n,int i,int j)
    {
        if(j==n)
        {
            return 1;
        }
        if(i==m)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int take=0,nottake=0;
        if(s[i]==t[j])
        {
           take=solve(dp,s,t,m,n,i+1,j+1);
        }
        
        nottake=solve(dp,s,t,m,n,i+1,j);
        
        
        return dp[i][j]=take+nottake;
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(dp,s,t,n,m,0,0);
        
    }
};

