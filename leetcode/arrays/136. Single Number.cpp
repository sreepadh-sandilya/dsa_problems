class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(auto i:nums)
        {
            a=(a^i);
        }
        return a;

    }
};
