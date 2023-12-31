class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,1);
        vector<int>count(n+1,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               if(arr[i]>arr[j] && dp[j]+1>dp[i])
               {
                   dp[i]=dp[j]+1;
                   count[i]=count[j];
               }
               else if(arr[i]>arr[j] && dp[j]+1==dp[i])
               {
                   count[i]+=count[j];
               }

            }
            maxi=max(maxi,dp[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                sum+=count[i];
            }
        }
        return sum;
        
        
    }
    
};
