class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>v(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[(j+k)%n]=mat[i][j];
            }
            if(v==mat[i])
            {
                for(int j=0;j<n;j++)
                {
                    v[j]=0;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
        
        
    }
};
