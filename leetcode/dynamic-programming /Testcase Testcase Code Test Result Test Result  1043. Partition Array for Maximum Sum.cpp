class Solution {
public:
    int solve(vector<int>&arr,int &k,vector<int>&dp,int &n,int i)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=0;
        int a=-1;
        for(int ind=0;ind<k;ind++)
        {
            if(i+ind<n){
            a=max(a,arr[i+ind]);
            ans=max(ans,a*(ind+1)+solve(arr,k,dp,n,ind+1+i));
            }
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,k,dp,n,0);
        
    }
};
