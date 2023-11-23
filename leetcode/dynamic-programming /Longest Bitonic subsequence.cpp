// memorization technique gives tle in gfg
class Solution{
	public:
	int solve(vector<vector<vector<int>>>&dp,vector<int>&nums,int &n,int i,int j,int dir)
	{
	    if(i==n)
	    {
	        return 0;
	    }
	    if(dp[i][j+1][dir]!=-1)
	    {
	        return dp[i][j+1][dir];
	    }
	    if(dir)
	    {
	        int take=0,nottake=0;
	        if(j==-1 || nums[i]>nums[j])
	        {
	            take=max(1+solve(dp,nums,n,i+1,i,1),1+solve(dp,nums,n,i+1,i,0));
	        } 
	        nottake=max(solve(dp,nums,n,i+1,j,1),solve(dp,nums,n,i+1,j,0));
	        return dp[i][j+1][dir]=max(take,nottake);
	    }
	    else
	    {
	        int take=0,nottake=0;
	        if(j==-1 || nums[i]<nums[j])
	        {
	            take=max(1+solve(dp,nums,n,i+1,i,0),1+solve(dp,nums,n,i+1,i,0));
	        }
	        nottake=solve(dp,nums,n,i+1,j,0);
	        return dp[i][j+1][dir]=max(take,nottake);
	    }
	    
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(2,-1)));
	    
	    return solve(dp,nums,n,0,-1,1);
	}
   
};

// bottom up approach:
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int>dp1(n,1);
	    vector<int>dp2(n,1);
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j])
	            {
	                dp1[i]=max(dp1[i],1+dp1[j]);
	            }
	        }
	    }
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[i]>nums[j])
	            {
	                dp2[i]=max(dp2[i],1+dp2[j]);
	            }
	        }
	    }
	    int k=-1;
	    for(int i=0;i<n;i++)
	    {
	        k=max(k,dp1[i]+dp2[i]-1);
	    }
	    return k;
	}
};
