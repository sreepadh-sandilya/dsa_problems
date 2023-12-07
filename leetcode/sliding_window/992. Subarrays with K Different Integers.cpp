class Solution {
public:
    int solve(vector<int>&s,int k)
    {
        if(k==0)
        {
            return 0;
        }
        int n=s.size(),sum=0,sum1=0,f=0,j=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==0)
            {
                mp[s[i]]++;
                f++;
            }
            else
            {
                mp[s[i]]++;
            }
            while(f>k && j<i)
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    f--;
                }
                j++;
                
            }
            sum1+=i-j+1;
            sum=max(sum,sum1);
            
        }
        return sum;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
