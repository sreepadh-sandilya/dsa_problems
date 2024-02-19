class Solution {
public:
    int solve(vector<vector<int>>&dp,int k,int f)
    {
        if(f==1 || f==0)
        {
            return f;
        }
        if(k==1)
        {
            return f;
        }
        if(dp[k][f]!=-1)
        {
            return dp[k][f];
        }
         int ans=INT_MAX,l=1,r=f;
         while(l<=r)
         {
             int mid=(l+r)/2;
             int left=1+solve(dp,k-1,mid-1);
             int right=1+solve(dp,k,f-mid);
             int temp=max(left,right);
             if(left<right)
             {
                 l=mid+1;
             }
             else
             {
                 r=mid-1;
             }
             ans=min(ans,temp);
         }

        return dp[k][f]=ans;

    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(dp,k,n);
    }
};
