class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v=arr;
        sort(v.begin(),v.end());
        unordered_map<int,int>mp;
        int k=1;
        for(int i=1;i<=v.size();i++)
        {
        if(mp.count(v[i-1])==0){
            mp[v[i-1]]=k;
            k++;
          }
        }
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
           ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};
