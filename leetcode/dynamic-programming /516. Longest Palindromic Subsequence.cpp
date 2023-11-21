class Solution {
public:
    int solve(vector<vector<int>>&dp,int &n,string &s,int i,int l)
    {
        if(i>=n || l<0 || i>l)
        {
            return 0;
        }
        if(l==i)
        {
           return 1;
        }
        if(dp[i][l]!=-1)
        {
            return dp[i][l];
        }
        if(s[i]==s[l])
        {
            dp[i][l]=2+solve(dp,n,s,i+1,l-1);
            return dp[i][l];
        }
        int ans=0;
        ans=max(solve(dp,n,s,i+1,l),solve(dp,n,s,i,l-1));
        dp[i][l]=ans;
        return ans;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // string t="";
        return solve(dp,n,s,0,n-1);
    }
};

