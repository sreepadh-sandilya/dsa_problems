class Solution {
public:
    int findMin(vector<int>& nums) {

        int ans=INT_MAX;
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(nums[i]<=nums[m])
            {
                ans=min(ans,nums[i]);
                i=m+1;
            }
            else
            {
                ans=min(ans,nums[m]);
                j=m-1;
            }

        }
        return ans;
        
    }
};
