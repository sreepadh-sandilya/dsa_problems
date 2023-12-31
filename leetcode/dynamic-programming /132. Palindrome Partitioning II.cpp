class Solution {
public:
    bool ispal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int &n,int i,vector<int>&dp)
    {

        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=INT_MAX;
        for(int ind=i;ind<=n-1;ind++)
        {
           if(ispal(s,i,ind))
           {
              
                ans=min(ans,1+solve(s,n,ind+1,dp));    
           }       
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solve(s,n,0,dp)-1;
    }
};
