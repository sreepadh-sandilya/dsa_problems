class Solution {
  public:

    int solve(vector<int>&nums,int prev,int ind,vector<vector<int>>&dp){
       if(ind>=nums.size())return 0;
       if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

         int take=0,nottake=0;
         if(prev==-1 || nums[ind]>nums[prev] && nums[ind]-nums[prev]>=ind-prev)
         {
             take=1+solve(nums,ind,ind+1,dp);
         }
         nottake=solve(nums,prev,ind+1,dp);
         
       return dp[ind][prev+1]=max(take,nottake);
       
   }
    
    int min_operations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(nums,-1,0,dp);
        return n-ans;
    }
};
