class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int n=nums.size();

        int sum=0,j=0,sum1=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
            while(sum1>k && j<=i)
            {
                sum1-=nums[j];
                j++;
            }
            if(j<=i)
            {
               sum+=i-j+1;
            }
            
        }
        return sum;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                nums[i]=0;
            }
            else
            {
                nums[i]=1;
            }
        }
        return  solve(nums,k)-solve(nums,k-1);
        
    }
};
