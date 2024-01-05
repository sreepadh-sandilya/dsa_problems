class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[i]=i;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    // dp[i]=max(dp[i],dp[j]+1);
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        mp[i]=j;
                    }
                }
            }
        }
        vector<int>ans;
        int a=-1,k=0;
        for(int i=0;i<n;i++)
        {
            if(a<dp[i])
            {
                a=dp[i];
                k=i;
            }
        }
        while(true)
        {
            if(mp[k]==k)
            {
                ans.push_back(nums[k]);
                break;
            }
            ans.push_back(nums[k]);
            k=mp[k];
            
        }
        return ans;


        
    }
};
