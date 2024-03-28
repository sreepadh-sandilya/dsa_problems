class Solution {
  public:
  
   static bool comp(pair<int,int>a,pair<int,int>b)
   {
       if(a.first==b.first)
       {
           return b.second<a.second;
       }
       return a.first<b.first;
   }
    
    void solve(vector<vector<pair<int,int>>>&adj,int &d,int &node, vector<pair<int,int>>&ans,int &n)
    {
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[node]=0;
        pq.push({0,node});
        while(!pq.empty())
        {
            pair<int,int>temp=pq.top();
            pq.pop();
            int nd=temp.second,di=temp.first;
            // if(di>d)
            // {
            //     continue;
            // }
            for(auto i:adj[nd])
            {
                if(di+i.second<dist[i.first])
                {
                    dist[i.first]=di+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
            
        }
        
        int sum=0;
        for(auto i:dist)
        {
            if(i<=d)
            {
                sum++;
            }
        }
        
        ans.push_back({sum,node});
        // for(auto i:dist)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
    }
    int findCity(int n, int m, vector<vector<int>>& edges, int d) {
        // Your code here
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges)
        {
            
                adj[i[0]].push_back({i[1],i[2]});
                adj[i[1]].push_back({i[0],i[2]});
            
        }
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
        {
            solve(adj,d,i,ans,n);
        }
        sort(ans.begin(),ans.end(),comp);
        // for(auto i:ans)
        // {
        //     cout<<i.second<<" "<<i.first<<endl;
        // }
        // cout<<endl;
        return ans[0].second;
        
    }
};
