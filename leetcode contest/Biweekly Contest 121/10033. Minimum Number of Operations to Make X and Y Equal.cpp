class Solution {
public:
    int solve(int x,int &y,vector<int>&dp)
    {
        if(x<=y)
        {
            return y-x;
        }
        if(dp[x]!=-1)
        {
            return dp[x];
        }
        int diff=abs(y-x);
        int op1=1+x%5+solve(x/5,y,dp);
        int op2=1+(5-x%5)+solve((x/5+1),y,dp);
        int op3=1+x%11+solve(x/11,y,dp);
        int op4=1+(11-x%11)+solve((x/11+1),y,dp);
        return dp[x]=min({diff,op1,op2,op3,op4});
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int>dp(100000,-1);
        int m=abs(x-y);
        return solve(x,y,dp);

        
    }
};
