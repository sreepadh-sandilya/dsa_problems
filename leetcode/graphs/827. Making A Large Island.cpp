class disjointset{
    
    public:
        vector<int>rank,parent,size;
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
        
    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
        
    
};



class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjointset ds(n*n+1);
        // map<int,int>mp;
        vector<int>x={-1, 0, 1, 0};
        vector<int>y={0, 1, 0, -1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    // mp[{i,j}]++;
                    int nodeno=i*n+j;
                    // mp[nodeno]++;
                    for(int k=0;k<4;k++)
                    {
                        int newr=x[k]+i;
                        int newc=y[k]+j;
                        if(newr>=0 && newr<n && newc>=0 && newc<n){
                        int adjno=newr*n+newc;

                        if(grid[newr][newc]==1)
                        {
                            
                                ds.unionBySize(nodeno,adjno);
                                //    mp[ds.findUpar(nodeno)]++;

                            
                        }
                       }
                    }
                }
            }
        }


        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int sum=0;
                    int nodeno=i*n+j;
                    unordered_set<int>st;
                    for(int k=0;k<4;k++)
                    {
                       int newr=x[k]+i;
                       int newc=y[k]+j;
                    //    cout<<newr<<" "<<newc<<endl;
                       if(newr>=0 && newr<n && newc>=0 && newc<n)
                       {
                           
                          if(grid[newr][newc]==1)
                          {
                              
                              int adjno=newr*n+newc;
                              int p=ds.findUpar(adjno);
                              cout<<adjno<<" "<<p<<endl;
                              if(st.find(p)==st.end())
                              {
                                  st.insert(p);
                                  sum+=ds.size[p];

                              }
                          }
                       }
                       
                        
                    }
                    maxi=max(maxi,sum+1);
                }
            }
        }
        
        for(int i=0;i<n*n;i++)
        {
            maxi=max(maxi,ds.size[ds.findUpar(i)]);
        }

        return maxi;

    }
};
