

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        long long sum=nums[0]+nums[1],maxi=0,j=0;

        int n=nums.size();
        for(int i=2;i<n;i++)
        {
            if(sum>nums[i])
            {
                maxi=sum+nums[i];
            }
            sum+=nums[i];
        }
        if(maxi==0)
        {
            return -1;
        }
        return maxi;
    }
};
