class Solution {
public:
    bool solve(string &s,unordered_map<string,int>&mp,vector<string>& wordDict,int i,vector<int>&dp)
    {
        if(i==s.length())
        {
            return true;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        for(int j=i;j<s.length();j++)
        {

           if(mp[s.substr(i,j-i+1)]==1)
           {

              
               if(solve(s,mp,wordDict,j+1,dp))
               {
                   return true;
               }
              
           }
        }
        return dp[i]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto i:wordDict)
        {
            mp[i]=1;
        }
        vector<int>dp(s.length(),-1);
        bool ans=solve(s,mp,wordDict,0,dp);
        return ans;
        
    }
};
