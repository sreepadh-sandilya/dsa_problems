class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int mini=1,maxi=INT_MIN;
        for(auto i:nums)
        {
            maxi=max(maxi,i);
            
        }
        int i=mini,j=maxi,ans=INT_MAX;
        while(i<=j)
        {
            int m=(i+j)/2,sum=0;
            for(auto k:nums)
            {
               sum+=(ceil((double)k/m));
            }
            if(sum<=threshold)
            {
                ans=min(ans,m);
                j=m-1;
            }
            else
            {
                i=m+1;
            }
        }

        return ans;
    }
};
