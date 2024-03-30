class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto i:bloomDay)
        {
            maxi=max(maxi,i);
            mini=min(mini,i);
        }
        int i=mini,j=maxi,ans=INT_MAX;
        while(i<=j)
        {
            int mid=(i+j)/2;
            int cnt=0,sum=0;
            for(int at=0;at<bloomDay.size();at++)
            {
                if(bloomDay[at]<=mid)
                {
                    cnt++;
                    if(at==bloomDay.size()-1)
                    {
                        sum+=cnt/k;
                    }
                }
                else
                {
                    sum+=cnt/k;
                    cnt=0;
                }
            }
            cout<<i<<" "<<j<<" "<<mid<<" "<<sum<<endl;
            if(sum>=m)
            {
                ans=min(ans,mid);
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
            
        }

        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
