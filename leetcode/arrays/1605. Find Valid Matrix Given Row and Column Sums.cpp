class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int n=r.size(),m=c.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        int i=0,j=0;
        while(i<n && j<m){
            if(r[i]<c[j])
            {
                ans[i][j]=r[i];
                c[j]-=r[i];
                r[i]=0;
                i++;
                if(c[j]==0)
                {
                    j++;
                }
            }
            else{
                ans[i][j]=c[j];
                r[i]-=c[j];
                c[j]=0;
                j++;
                if(r[i]==0)
                {
                    i++;
                }
            }
        }
        return ans;
    }
};
