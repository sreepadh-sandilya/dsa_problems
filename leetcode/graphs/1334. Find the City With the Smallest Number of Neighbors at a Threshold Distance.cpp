class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        map<int,vector<int>>mp;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        for(int i=0;i<n;i++)
        {
            vector<int>dist(n+1,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            dist[i]=0;
            pq.push({0,i});
            int sum=0;
            while(!pq.empty()){
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto j:adj[node])
                {
                    if(d+j.second<dist[j.first]){
                        dist[j.first]=d+j.second;
                        pq.push({dist[j.first],j.first});
                    }
                }

            }
            for(int i=0;i<n;i++)
            {
                if(dist[i]<=distanceThreshold){
                    sum++;
                }
            }
            mp[sum].push_back(i);
            
        }
        vector<int>anss=mp.begin()->second;
        sort(anss.begin(),anss.end(),greater<int>());
        return anss[0];

    }
};
