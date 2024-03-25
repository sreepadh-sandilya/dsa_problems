class Solution {
public:
    int solve(vector<int>& nums, int target,int i,int j)
    {
        while(i<=j)
        {
            int m=(i+j)/2;
            if(nums[m]==target)
            {
                return m;
            }
            if(nums[i]<=nums[m])
            {
                if(nums[i]<=target && target<nums[m])
                {
                     j=m-1;
                }
                else
                {
                    i=m+1;
                }
            }
            else
            {
                if(nums[m]<target && nums[j]>=target)
                {
                    i=m+1;
                }
                else
                {
                    j=m-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return solve(nums,target,0,nums.size()-1);

        
    }
};
