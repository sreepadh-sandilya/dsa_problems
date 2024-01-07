class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int,int>mp;
        if(nums.size()==1)
        {
            return nums[0]+1;
        }
        for(auto i:nums)
        {
            mp[i]++;
        }
        int sum=nums[0],maxi=nums[0],k=1,d=1;;
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]==nums[i-1]+1)
            {
                sum+=nums[i];
                maxi=sum;
            }
            else
            {
                break;
            }
            i++;
        }
        
        while(true)
        {
            if(mp.find(maxi)==mp.end())
            {
                return maxi;
            }
            else
            {
                maxi++;
            }
        }
        
    }
};
