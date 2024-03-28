class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int j=0,maxf=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
          mp[nums[i]]++;
          while(j<i && mp[nums[i]]>k)
          {
            mp[nums[j]]--;
            j++;
          }
          
          
          sum=max(sum,i-j+1);
        }
        return sum;
    }
};
