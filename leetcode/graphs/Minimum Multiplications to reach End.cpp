#define mod 100000
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end)
        {
            return 0;
        }
        vector<int>dist(100000,INT_MAX);
        queue<pair<int,int>>pq;
        pq.push({0,start});
        while(!pq.empty())
        {
            int d=pq.front().first;
            int num=pq.front().second;
            pq.pop();
            if(num==end)
            {
                return d;
            }
            for(auto i:arr)
            {
                int n=(num*i)%mod;
                if(n==end)
                {
                    return d+1;
                }
                if(dist[n]>d+1)
                {
                    pq.push({d+1,n});
                    dist[n]=d+1;
                }
            }
        }
        return -1;
        
        
    }
};
