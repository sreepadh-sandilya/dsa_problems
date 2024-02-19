class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<pair<int,int>>pq;
        unordered_map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second*i.second,i.second});
        }
        int sum=0;
        while(k--)
        {
            int n=pq.top().second-1;
            pq.pop();
            pq.push({n*n,n});
        }
        
        while(!pq.empty())
        {
            int n=pq.top().first;
            sum+=n;
            pq.pop();
        }
        
        return sum;
        
        
    }
};
