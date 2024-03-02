class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(),i=0,j=n-1;
        vector<int>ans;
        while(i<=j)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
               ans.push_back(nums[j]*nums[j]);
               j--;
            }
            else
            {
                ans.push_back(nums[i]*nums[i]);
               i++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
