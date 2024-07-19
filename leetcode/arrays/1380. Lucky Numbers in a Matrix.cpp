class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int>mini;
        set<int>maxi;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            int mi=INT_MAX;
            for(int j=0;j<m;j++)
            {
                mi=min(mi,matrix[i][j]);
            }
            mini.insert(mi);
        }
        for(int i=0;i<m;i++){
            int ma=INT_MIN;
            for(int j=0;j<n;j++)
            {
                ma=max(ma,matrix[j][i]);
            }
            maxi.insert(ma);
        }
        vector<int>ans;
        for(auto i:mini)
        {
            if(maxi.find(i)!=maxi.end()){
                 ans.push_back(i);
            }
        }

        return ans;
    }
};
