class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<pair<int,int>>v;
        unordered_map<int,int>mp;
        for(auto i:arr)
        {
            mp[i]++;
        }

        for(auto i:mp)
        {
            v.push_back({i.second,i.first});
        }
        int n=v.size();
        // cout<<n<<endl;
        int i=0;
        sort(v.begin(),v.end());
        while(i<n && k)
        {
            // cout<<k<<" "<<i<<endl;
            if(v[i].first<=k)
            {
                k-=v[i].first;
                i++;
            }
            else
            {
                break;
            }


        }
        
        return n-i;
    }
};
