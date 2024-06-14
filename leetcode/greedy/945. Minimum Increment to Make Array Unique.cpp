
// 1 1 2 2 3 7
// 1 2 2 2 3 7
// 1 2 3 2 3 7
// 1 2 3 4 3 7
// 1 2 3 4 5 7
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
               sum+=nums[i-1]+1-nums[i];
               nums[i]=nums[i-1]+1;
            }
        }
        return sum;
    }
};
