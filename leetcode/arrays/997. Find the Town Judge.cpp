class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1,0);
        vector<int>v1(n+1,0);
        for(auto i:trust)
        {
            v[i[1]]++;
            v1[i[0]]++;
        }

        for(int i=1;i<=n;i++)
        {
            if(v[i]==n-1 && v1[i]==0)
            {
               return i;
            }
        }
        return -1;
        
    }
};
