class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int>ans;
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n+1,INT_MAX);
        dist[0]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:meetings)
        {
            
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
            
        }

        dist[firstPerson]=0;
        pq.push({0,0});
        if(firstPerson!=0){
        pq.push({0,firstPerson});
        }
        
        while(!pq.empty())
        {
            int t=pq.top().first;
            int node=pq.top().second;

            
            pq.pop();
            
            for(auto i:adj[node])
            {
                if(dist[i.first]>t && i.second>=t)
                {
                    pq.push({i.second,i.first});
                   
                    dist[i.first]=i.second;
                    
                }
            }
           
        }

        for(int i=0;i<=n;i++)
        {
            cout<<i<<" "<<dist[i]<<endl;
            if(dist[i]!=INT_MAX)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
