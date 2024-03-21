class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
          mp[i]++;
        }

        vector<int>ans;
        vector<vector<int>>b(nums.size()+1);
        for(auto i:mp)
        {
            b[i.second].push_back(i.first);
        }
        for(int i=b.size()-1;i>=0 && ans.size()<k;i--)
        {
            for(auto j:b[i])
            {
               ans.push_back(j);
            }
        }
        return ans;

        
    }
};
