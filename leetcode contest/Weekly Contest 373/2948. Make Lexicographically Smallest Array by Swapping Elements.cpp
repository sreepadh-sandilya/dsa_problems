class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        unordered_map<int,vector<pair<int,int>>>mp;
        int k=0;
        for(int i=0;i<n;i++)
        {
           if(i==0)
           {
               mp[k].push_back(v[i]);
           }
           else if(v[i].first-v[i-1].first<=limit)
           {
               mp[k].push_back(v[i]);
           }
           else
           {
               k++;
               mp[k].push_back(v[i]);
           }
        }

        vector<int>ans(n,0);
        for(auto i:mp)
        {
            vector<int>p;
            for(auto j:i.second)
            {
                p.push_back(j.second);
            }
            sort(p.begin(),p.end());
            int k=0;
            for(auto j:i.second)
            {
                ans[p[k]]=j.first;
                k++;
            }
        }

        return ans;
        
    }
};
