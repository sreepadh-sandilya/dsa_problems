class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,ans=INT_MAX,mini=INT_MIN;
        for(auto i:weights)
        {
            sum+=i;
            mini=max(mini,i);
        }
        int i=mini,j=sum;
        while(i<=j)
        {
            int m=(i+j)/2;
            int cnt=0;
            sum=0;
            for(int k=0;k<weights.size();k++)
            {
               sum+=weights[k];
               if(sum>m)
               {
                 cnt++;
                 sum=weights[k];
                if(k==weights.size()-1){
                    cnt++;
                }
               }
               else
               {
                if(k==weights.size()-1){
                    cnt++;
                }

               }
            }
            
            if(cnt>days){
                i=m+1;
            }
            else
            {
                ans=min(ans,m);
                j=m-1;
            }
        }
        return ans;
    }
};
