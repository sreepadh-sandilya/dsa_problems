class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        unordered_set<int>st;
        for(auto i:nums)
        {
            st.insert(i);
        }
        int count=1,sum=1;
        for(auto i:st)
        {
            if(st.find(i-1)==st.end())
            {
                
                int k=i+1;

                while(st.find(k)!=st.end())
                {
                    k++;
                    sum++;
                }
            }
            count=max(count,sum);
            sum=1;
        }

        return count;
    }
};
