class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<=n;i++)
        {
            int ans=-1;
            int a=0,b=n-1;
            while(a<=b)
            {
                int m=(a+b)/2;
                if(nums[m]>=i)
                {
                    ans=max(ans,n-m);
                    b=m-1;
                }
                else{
                    a=m+1;
                }
                

            }
            if(ans==i)
                {
                    return i;
                }
        }
        return -1;
    }
};
// 00344
