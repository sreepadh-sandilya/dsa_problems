class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // unordered_map<int,int>mp;
        int sum=0,j=0,n=nums.size(),a=0,b=0;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==1)
           {
               b++;
           }
           else{
               a++;
           }
           while(a>k)
           {
               if(nums[j]==0)
               {
                   a--;
               }
               else
               {
                   b--;
               }
               j++;
           }
           sum=max(sum,a+b);

        }
        return sum;

        
        
    }
};
