class Solution {
public:
    vector<int> findPeaks(vector<int>& mo) {
        vector<int>ans;
        int n=mo.size();
        for(int i=1;i<n-1;i++)
        {
            if(mo[i+1]<mo[i] && mo[i-1]<mo[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
