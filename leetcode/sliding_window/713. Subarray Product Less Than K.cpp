class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int mul=1,sum=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
           mul*=nums[i];
           while(mul>=k && j<i)
           {
            mul/=nums[j];
            j++;
           }
           if(mul<k){
           sum+=i-j+1;
           }
           cout<<mul<<" "<<sum<<endl;
        }

        return sum;
    }
};
