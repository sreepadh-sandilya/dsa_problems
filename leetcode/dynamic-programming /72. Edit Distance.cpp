class Solution {
public:
    int solve(string &word1, string &word2,int n,int m,vector<vector<int>>&dp,int i,int j)
    {
        if(j>=m)
        {
            return n-i;
        }
        if(i>=n)
        {
            
            return m-j;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(word1[i]==word2[j])
        {
            return dp[i][j]=solve(word1,word2,n,m,dp,i+1,j+1);
        }
        else
        {
            int insert=1+solve(word1,word2,n,m,dp,i,j+1);
            int delet=1+solve(word1,word2,n,m,dp,i+1,j);
            int replace=1+solve(word1,word2,n,m,dp,i+1,j+1);
            return dp[i][j]=min(insert,min(delet,replace));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        if(n==0)
        {
            return m;
        }
        if(m==0)
        {
            return n;
        }

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,n,m,dp,0,0);
        
    }
};
