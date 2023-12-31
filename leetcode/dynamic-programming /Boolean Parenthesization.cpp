class Solution{
public:
    int mod=1003;
    int solve(int &n,string &s,int i,int j,bool isTrue,vector<vector<vector<int>>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            if(isTrue==true)
            {
                return s[i]=='T';
            }
            else
            {
                return s[i]=='F';
            }
        }
        if(dp[i][j][isTrue]!=-1)
        {
            return dp[i][j][isTrue];
        }
        int ways=0;
        for(int ind=i+1;ind<j;ind+=2)
        {
            int lt=solve(n,s,i,ind-1,1,dp);
            int lf=solve(n,s,i,ind-1,0,dp);
            int rt=solve(n,s,ind+1,j,1,dp);
            int rf=solve(n,s,ind+1,j,0,dp);
            
            if(s[ind]=='&')
            {
                if(isTrue)
                {
                    ways=(ways+(lt*rt)%mod)%mod;
                }
                else
                {
                    ways=(ways+(lf*rt)%mod+(lf*rf)%mod+(lt*rf)%mod)%mod;
                }
            }
            else if(s[ind]=='|')
            {
                if(isTrue)
                {
                    ways=(ways+(lt*rt)%mod+(lf*rt)%mod+(lt*rf)%mod)%mod;
                }
                else
                {
                    ways=(ways+(lf*rf)%mod)%mod;
                }
            }
            else
            {
                if(isTrue)
                {
                    
                    ways=(ways+(lf*rt)%mod+(lt*rf)%mod)%mod;
                    
                    
                }
                else
                {
                    ways=(ways+(lt*rt)%mod+(lf*rf)%mod)%mod;
                }
            }
            
        }
        return dp[i][j][isTrue]=ways;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        
        return solve(n,s,0,n-1,1,dp);
    }
};
