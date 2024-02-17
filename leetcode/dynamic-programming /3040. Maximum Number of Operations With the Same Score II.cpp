class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>>&dp,int i,int j,int sum,int &n)
    {
        if(i>=n || j>=n || i<0 || j<0  || i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a=0,b=0,c=0;
        if(i+2<n && nums[i]+nums[i+1]==sum)
        {
            a=1+solve(nums,dp,i+2,j,sum,n);
        }
        if(i+1<n && j-1 >=0 && nums[i]+nums[j]==sum)
        {
            b=1+solve(nums,dp,i+1,j-1,sum,n);
        }
        if(j-2>=0 && nums[j]+nums[j-1]==sum)
        {
            c=1+solve(nums,dp,i,j-2,sum,n);
        }
        // return dp[i][j]=1+max({solve(nums,dp,,j+2,sum,n),solve(nums,dp,i+1,j-1,sum,n),solve(nums,dp,i-2,1-1,sum,n)});
        // cout<<i<<" "<<j<<" "<<max({a,b,c})<<endl;
        return dp[i][j]=max({a,b,c});
        
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=1+max({solve(nums,dp,2,n-1,nums[0]+nums[1],n),solve(nums,dp,1,n-2,nums[0]+nums[n-1],n),solve(nums,dp,0,n-3,nums[n-1]+nums[n-2],n)});
        return ans;
        
    }
};
