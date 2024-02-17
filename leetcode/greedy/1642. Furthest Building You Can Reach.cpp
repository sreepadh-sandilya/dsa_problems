class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n=h.size(),sum1=0,sum2=0;
        if(n==0 || n==1)
        {
            return 0;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<n;i++)
        {
            if(h[i]<=h[i-1])
            {
                continue;
            }
            if(l)
            {
                pq.push(h[i]-h[i-1]);
                // sum1+=h[i]-h[i-1];
                l--;
                
                continue;
            }
            if(!pq.empty() && pq.top()<h[i]-h[i-1])
            {
                sum2+=pq.top();

                pq.pop();
                pq.push(h[i]-h[i-1]);


            }
            else
            {
              sum2+=h[i]-h[i-1];
            }
            if(sum2>b)
            {
                return i-1;
            }
        }

        return n-1;
    }

};
