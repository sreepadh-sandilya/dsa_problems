class Solution{

	public:
	int mod=1e9+7;
	int solve(vector<vector<int>>&dp,int arr[],int n,int sum,int s,int i)
	{
	    if(s>sum)
	    {
	        return 0;
	    }
	    if(i==n)
	    {
	        if(s==sum)
	        {
	            return 1;
	        }
	        else
	        {
	            return 0;
	        }
	    }
	    if(s==sum)
	    {
	        int k=0;
	        for(int j=i;j<n;j++)
	        {
	            if(arr[j]==0)
	            {
	                
	                k++;
	                
	            }
	            else
	            {
	                break;
	            }
	        }
	        return 1+k;
	    }

	    if(dp[s][i]!=-1)
	    {
	        return dp[s][i];
	    }
	    
	    int take=solve(dp,arr,n,sum,s+arr[i],i+1);
	    int nottake=solve(dp,arr,n,sum,s,i+1);

	    dp[s][i]=(nottake+take)%mod;
	    return dp[s][i];
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(sum,vector<int>(n,-1));
        int s=0;
        return solve(dp,arr,n,sum,s,0);
	}
	  
};
