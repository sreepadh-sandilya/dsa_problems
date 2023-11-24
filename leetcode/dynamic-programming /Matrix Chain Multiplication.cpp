class Solution{
public: 

    int solve(vector<vector<int>>&dp,int arr[],int &n,int i,int j)
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            ans=min(ans,arr[i-1]*arr[k]*arr[j]+solve(dp,arr,n,i,k)+solve(dp,arr,n,k+1,j));
        }
        dp[i][j]=ans;
        return ans;

    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(dp,arr,n,1,n-1);
    }
};
