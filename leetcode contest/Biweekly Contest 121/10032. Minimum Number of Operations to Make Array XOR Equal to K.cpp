class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int sum=0;
        for(auto i:nums)
        {
            sum=(sum^i);
            // cout<<sum<<endl;
        }
        sum=(sum^k);
        // cout<<sum<<endl;
        int count=0;
        while(sum)
        {
            if(sum%2!=0)
            {
                count++;
            }
             sum/=2;
        }
        return count;
        
    }
};
