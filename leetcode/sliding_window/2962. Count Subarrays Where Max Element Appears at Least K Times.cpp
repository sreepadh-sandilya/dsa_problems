class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long sum=0,n=nums.size();
        int maxi=0;
        for(auto i:nums)
        {
            maxi=max(maxi,i);
        }
        long long total=n*(n+1)/2;
        long long j=0,count=0;
        for(long long i=0;i<n;i++)
        {
            if(nums[i]==maxi)
            {
                count++;
            }
            while(count>=k && j<=i)
            {
                if(nums[j]==maxi)
                {
                    count--;
                }
                j++;
            }
            
            
            sum+=i-j+1;
            
        }
        return total-sum;
        
    }
};
