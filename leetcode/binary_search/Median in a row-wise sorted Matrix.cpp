class Solution{   
public:
    int upperbound(vector<int> &row, int R, int C,int n){
        int i=0,j=C-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(row[mid]<n)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return i;
    }
    int solve(vector<vector<int>> &matrix, int R, int C,int n){
        int sum=0;
        for(int i=0;i<R;i++)
        {
            sum+=upperbound(matrix[i],R,C,n);
        }
        return sum;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here     
        int maxi=INT_MAX,mini=INT_MIN;
        for(int i=0;i<R;i++){
            maxi=max(maxi,matrix[i][C-1]);
            mini=min(mini,matrix[i][0]);
        }
        int i=mini,j=maxi,middle=R*C/2;
        while(i<=j)
        {
            int mid=(i+j)/2;
            int count=solve(matrix,R,C,mid);
            if(count<=middle){
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return j;
    }
};
