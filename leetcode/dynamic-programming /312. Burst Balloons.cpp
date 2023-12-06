class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>>&dp,int n,int i,int j)
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int k=i;k<j;k++)
        {
            ans=max(ans,nums[i-1]*nums[k]*nums[j] + solve(nums,dp,n,i,k)+solve(nums,dp,n,k+1,j));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        
        // int m=nums[0].size();
        
        // map<int,int>mp;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,dp,n,1,n-1);
        
    }
};

