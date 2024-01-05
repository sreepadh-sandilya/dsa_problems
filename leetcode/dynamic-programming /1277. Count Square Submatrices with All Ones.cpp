class Solution {
public:
    int countSquares(vector<vector<int>>& ma) {
        int n=ma.size(),m=ma[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int sum=0;
        for(int i=0;i<m;i++)
        {
           dp[0][i]=ma[0][i];
           sum+=dp[0][i];
        } 
        for(int i=1;i<n;i++)
        {
            dp[i][0]=ma[i][0];
            sum+=dp[i][0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(ma[i][j]==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    sum+=dp[i][j];
                }
            }
        }
        return sum;
    }
};
