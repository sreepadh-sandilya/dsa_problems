class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int m=n-k,sum=0;
        for(auto i:c)
        {
           sum+=i;
        }
        int sum1=0,j=0,z=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i<m)
            {
                sum1+=c[i];
            }
            else
            {
                z=min(z,sum1);
                sum1+=c[i];
                sum1-=c[j];
                j++;
                z=min(z,sum1);
                
            }
            // cout<<sum1<<endl;
            
        }
        return sum-z;

    }
};
