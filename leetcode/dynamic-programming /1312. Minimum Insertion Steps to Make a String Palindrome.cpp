class Solution {
public:
    int solve(vector<vector<int>>&dp,string &s,int i,int j,int &n)
    {
        if(i>=n || j<0 || i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            dp[i][j]=2+solve(dp,s,i+1,j-1,n);
            return dp[i][j];
        }
        int ans=0;
        ans=max(solve(dp,s,i+1,j,n),solve(dp,s,i,j-1,n));
        dp[i][j]=ans;
        return ans;
    }
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n-solve(dp,s,0,n-1,n);

        
        
    }
};
