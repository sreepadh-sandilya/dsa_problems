class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(vector<vector<int>>&dp,int w,int wt[], int val[],int n,int i,int sum)
    {
        if(i>=n)
        {
            return 0;
        }
        if(sum>w)
        {
            return 0;
        }
        if(dp[sum][i]!=-1)
        {
            return dp[sum][i];
        }
        int ans=INT_MIN,take=0,nottake=0;
        if(sum+wt[i]<=w){
        take=val[i]+solve(dp,w,wt,val,n,i+1,sum+wt[i]);
        }
        nottake=solve(dp,w,wt,val,n,i+1,sum);
        ans=max(take,nottake);
        dp[sum][i]=ans;
        return ans;
        
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       int sum=0;
       for(int i=0;i<n;i++)
       {
           sum+=wt[i];
       }
       
       vector<vector<int>>dp(sum,vector<int>(n,-1));
       return solve(dp,w,wt,val,n,0,0);
    }
};
