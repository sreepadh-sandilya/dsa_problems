class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int>ans;
        vector<int>dp(n+1,1);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        mp[i]=j;
                        
                    }
                }
            }
        }
        int a=dp[0],k=0;
        for(int i=1;i<n;i++)
        {
            if(dp[i]>a)
            {
                a=dp[i];
                k=i;
            }
        }
        
        while(k!=mp[k]){
            ans.push_back(arr[k]);
            k=mp[k];
            
        }
        ans.push_back(arr[k]);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
