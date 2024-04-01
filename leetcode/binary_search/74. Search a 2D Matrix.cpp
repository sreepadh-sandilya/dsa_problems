class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=n-1;
        int ans=INT_MIN;
        while(i<=j)
        {
            int mid=(i+j)/2;
            cout<<mid<<endl;
            if(matrix[mid][0]<=target)
            {
              i=mid+1;
              ans=max(ans,mid);
            }
            else
            {
                
                j=mid-1;
            }
        }
        if(ans==INT_MIN)
        {
          return false;
        }
        i=0,j=m-1;
        cout<<ans<<endl;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(matrix[ans][mid]==target)
            {
                return true;
            }
            if(matrix[ans][mid]<target)
            {
              i=mid+1;
            }
            else
            {
                
                j=mid-1;
            }
        }
        return false;
    }
};
