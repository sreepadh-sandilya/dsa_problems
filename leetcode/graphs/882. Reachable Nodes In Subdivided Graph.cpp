class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[0]=0;
        pq.push({0,0});
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
             pq.pop();
            for(auto i:adj[node])
            {
               if(d+i.second+1<dist[i.first])
               {
                   dist[i.first]=d+i.second+1;
                   pq.push({dist[i.first],i.first});
               }
            }
            
        }
        int sum=0;
        for(auto i:edges)
        {
            int a,b;
            if(dist[i[0]]>maxMoves)
            {
              a=0;
            }
            else
            {
                a=min(i[2],maxMoves-dist[i[0]]);
            }
            if(dist[i[1]]>maxMoves)
            {
                b=0;
            }
            else
            {
                b=min(i[2],maxMoves-dist[i[1]]);
            }
            sum+=min(a+b,i[2]);
        }

        for(auto i:dist)
        {
            if(i<=maxMoves)
            {
                sum++;
            }
        }
        return sum;


        
    }
};
