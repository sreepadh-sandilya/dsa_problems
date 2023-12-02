class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<int>& cuts,int i,int j)
    {
       if(i>j)
       {
           return 0;
       }
       if(dp[i][j]!=-1)
       {
           return dp[i][j];
       }
       int ans=INT_MAX;
       for(int k=i;k<=j;k++)
       {
          ans=min(ans,cuts[j+1]-cuts[i-1]+solve(dp,cuts,i,k-1)+solve(dp,cuts,k+1,j));
       }
       return dp[i][j]=ans;

    }
    int minCost(int n, vector<int>& cuts) {
        
        int m=cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return solve(dp,cuts,1,m);
        
    }
};
