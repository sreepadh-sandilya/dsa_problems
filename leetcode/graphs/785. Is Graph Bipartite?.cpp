class Solution {
public:

    bool check(vector<vector<int>>& graph,vector<int>&color,int c,int n,int m,int node)
    {
        for(auto i:graph[node])
        {
            if(c==color[i])
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph,vector<bool>&vis,vector<int>&color,int n,int m,int node,int c)
    {
        vis[node]=true;
        if(check(graph,color,c,n,m,node))
        {
            color[node]=c;
        }
        else
        {
            return false;
        }
       for(auto i:graph[node])
       {
           if(!vis[i])
           {
               if(c==0)
               {
                if(!dfs(graph,vis,color,n,m,i,1))
                {
                    return false;
                }
               }
               else
               {
                   if(!dfs(graph,vis,color,n,m,i,0))
                   {
                       return false;
                   }
               }
           }
       }
       return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size(),m=graph[0].size();
        vector<bool>vis(n,false);
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!dfs(graph,vis,color,n,m,i,0))
                {
                    return false;
                }
            }
        }
        return true;

        
    }
};
