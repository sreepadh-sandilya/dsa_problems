class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int sum=0,m=0;
        for(auto i:nums)
        {
            sum+=i;
            if(sum==k)
            {
                m++;
            }
            m+=mp[sum-k];
            mp[sum]++;

        }
        return m;
    }
};
