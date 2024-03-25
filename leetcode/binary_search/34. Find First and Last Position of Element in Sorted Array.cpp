class Solution {
public:
    int solve(vector<int>& nums, int target,int i,int j)
    {
        while(i<=j)
        {
            int m=(i+j)/2;
            if(nums[m]<target)
            {
                i=m+1;
            }
            else
            {
                j=m-1;
            }

        }
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=solve(nums,target,0,nums.size()-1);
        int h=solve(nums,target+1,0,nums.size()-1)-1;
        if(l<nums.size() && nums[l]==target)
        {
            return {l,h};
        }
        return {-1,-1};
    }
};
