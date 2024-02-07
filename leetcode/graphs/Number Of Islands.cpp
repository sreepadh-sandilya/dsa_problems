class disjointset{
    vector<int>rank,parent,size;
    public:
        disjointset(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }
        
        int findUpar(int node)
        {
            if(node==parent[node])
            {
                return node;
            }
            return parent[node]=findUpar(parent[node]);
        }
        
        void unionbyrank(int u,int v)
        {
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            if(ulp_u==ulp_v)
            {
                return;
            }
            if(rank[ulp_v]>rank[ulp_u])
            {
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u])
            {
                parent[ulp_v]=ulp_u;
            }
            else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void unionBySize(int u,int v)
        {
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            if(ulp_u==ulp_v)
            {
                return;
            }
            if(size[ulp_v]>size[ulp_u])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else if(size[ulp_v]<size[ulp_u])
            {
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        
    
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        disjointset ds(n*m+1);
        // unordered_map<int,int>mp;
        vector<int>ans;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        vector<int>x={-1, 0, 1, 0};
        vector<int>y={0, 1, 0, -1};
        for(auto i:op)
        {
           int r=i[0],c=i[1];
        //   op[r][c]=1;
           if(vis[r][c]==1)
           {
               ans.push_back(count);
               continue;
           }
           vis[r][c]=1;
           count++;
           
           for(int j=0;j<4;j++)
           {
               int newr=x[j]+r,newc=y[j]+c;
               
               if(newr>=0 && newr<n && newc>=0 && newc<m)
               {
                   if(vis[newr][newc]==1)
                   {
                       
                       int nodeno=r*m+c;
                       int adjno=newr*m+newc;
                       if(ds.findUpar(nodeno)!=ds.findUpar(adjno))
                       {
                           ds.unionbyrank(nodeno,adjno);
                           count--;
                       }
                   }
               }
           }
           ans.push_back(count);
        }
        return ans;
    }
};
