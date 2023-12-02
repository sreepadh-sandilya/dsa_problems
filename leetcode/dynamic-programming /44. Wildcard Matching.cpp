class Solution {
public:
    bool solve(string &s, string &p,int &n,int &m,int i,int j,vector<vector<int>>&dp)
    {
        if(i==n && j==m)
        {
            return true;
        }
        else if(i==n)
        {
            while(j<m)
            {
                if(p[j]!='*')
                {
                    return false;
                    
                }
                j++;
            }
            return true;
        }
        else if(j==m)
        {
            return false;
        }
        else if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else if(p[j]=='?')
        {

            return dp[i][j]=solve(s,p,n,m,i+1,j+1,dp);
        }
        else if(p[j]=='*')
        {
            return dp[i][j]=(solve(s,p,n,m,i+1,j+1,dp) || solve(s,p,n,m,i+1,j,dp) || solve(s,p,n,m,i,j+1,dp));           
        }
        else if(s[i]==p[j])
        {
            return dp[i][j]=solve(s,p,n,m,i+1,j+1,dp);
        }
        else
        {
            dp[i][j]=0;
            return false;
        }


        

    }
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        if(n==0)
        {
            for(auto i:p)
            {
                if(i!='*')
                {
                    return false;
                }
            }
            return true;
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,p,n,m,0,0,dp);
        
    }
};
