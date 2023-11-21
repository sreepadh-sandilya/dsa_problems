int solve(string &text1,string &text2,vector<vector<int>>&dp,int i1,int i2,int &m,int &n)
    {
        if(i1>=m)
        {
            return 0;
        }
        if(i2>=n)
        {
            return 0;
        }
        if(dp[i1][i2]!=-1)
        {
            return dp[i1][i2];
        }
        if(text1[i1]==text2[i2])
        {
            dp[i1][i2]=1+solve(text1,text2,dp,i1+1,i2+1,m,n);
            return dp[i1][i2];
        }
        else
        {
            dp[i1][i2]=max(solve(text1,text2,dp,i1,i2+1,m,n),solve(text1,text2,dp,i1+1,i2,m,n));
            return dp[i1][i2];
        }


    }

    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>>dp(max(m,n)+1,vector<int>(max(m,n)+1,-1));
        int k=solve(word1,word2,dp,0,0,m,n);
        return m+n-2*k;
        
    }
};
