class Solution {
public:
    double solve(map<string,vector<pair<string,double>>>&adj,string &src,string &dest)
    {
        queue<pair<string,double>>q;
        map<string,int>vis;
        q.push({src,1});
        while(!q.empty())
        {
            pair<string,double>temp=q.front();
            q.pop();
            string node=temp.first;
            vis[node]=1;
            double d=temp.second;
            if(node==dest)
            {
                return d;
            }
            for(auto i:adj[node])
            {
                if(vis[i.first]==0){
                q.push({i.first,(double)d*i.second});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>adj;
        int n=values.size();
        for(int i=0;i<n;i++)
        {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],(double)1/values[i]});
            // cout<<(double)1/values[i]<<endl;
        }
        vector<double>ans;
        for(auto i:queries)
        {
            if(adj.find(i[0])==adj.end() || adj.find(i[1])==adj.end())
            {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(solve(adj,i[0],i[1]));
        }
        return ans;

    }
};
