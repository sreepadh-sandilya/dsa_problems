class Solution {
public:
    int find(int m,vector<vector<int>>& mat,int n){
        int ans=0;
        int row=-1;
        for(int i=0;i<n;i++)
        {
            if(ans<mat[i][m]){
                ans=mat[i][m];
                row=i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int i=0,j=m-1;

        while(j>=i)
        {
            int mid=(i+j)/2;
            
            int row=find(mid,mat,n);
            // cout<<row<<" "<<mid<<endl;
            int left,right;
            if(mid-1>=0){
                left=mat[row][mid-1];
            }
            else
            {
                left=-1;
            }
            if(mid+1<=m-1){
                right=mat[row][mid+1];
            }
            else{
                right=-1;
            }
            if(left<mat[row][mid] && mat[row][mid]>right)
            {
                vector<int>v={row,mid};
                return v;
            }
            else if(right>mat[row][mid])
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return {};
    }
};
