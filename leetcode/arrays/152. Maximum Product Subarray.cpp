class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,suffix=1,maxi=-11,n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxi=max({prefix,suffix,maxi});
            if(prefix==0)
            {
                prefix=1;
            }
            if(suffix==0)
            {
                suffix=1;
            }
        }
        return maxi;
        
    }
};
