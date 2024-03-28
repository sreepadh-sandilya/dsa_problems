class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=-1,mini=INT_MAX,ans=INT_MAX;
        for(auto i:piles)
        {
            maxi=max(maxi,i);
            
        }
        int i=1,j=maxi;
        while(i<=j)
        {
            int m=(i+j)/2;
            int sum=0;
            for(auto i:piles)
            {
                sum+=ceil((double)i/m);
                if(sum>h)
                {
                    break;
                }
            }
            if(sum<=h)
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
