class Solution {
public:
    int solve(vector<int>&v)
    {
        sort(v.begin(),v.end());
        int ans=2,k=2;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1]+1)
            {
                k++;
            }
            else
            {
                k=2;
            }
            ans=max(ans,k);
        }
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int k=min(solve(hBars),solve(vBars));
        return k*k;
    }
};
