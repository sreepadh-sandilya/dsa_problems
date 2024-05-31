class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0,m=1,b=0;
        for(auto i:nums)
        {
            a=(i^a);
        }
        while(not (m & a))
        {
            m=m<<1;
        }
        for(auto i:nums)
        {
            if(i & m)
            {
                b=(b^i);
            }
        }
        vector<int>ans={b,(a^b)};
        return ans;
    }
};
