class Solution {
public:

    int solve(vector<int>& nums,map<pair<int,int>,int>&mp,int target,int n,int i, int sum)
    {
        if(i==n)
        {
            if(target==sum)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(mp.count({sum,i})!=0)
        {
            return mp[{sum,i}];
        }
        int take=solve(nums,mp,target,n,i+1,sum+nums[i]);
        int nottake=solve(nums,mp,target,n,i+1,sum-nums[i]);
        mp[{sum,i}]=take+nottake;
        return mp[{sum,i}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>mp;
        int n=nums.size();
        return solve(nums,mp,target,n,0,0);
        
    }
};
