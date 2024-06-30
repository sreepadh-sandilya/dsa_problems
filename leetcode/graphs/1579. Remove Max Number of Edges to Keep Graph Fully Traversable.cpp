class disjointset{
    vector<int>rank,parent,size;
    public:
        disjointset(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<n;i++)
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
            if(u==v)
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
    static bool comp(vector<int>a,vector<int>b)
    {
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end());
        int sum=0,m=edges.size();
        disjointset alice(n+1);
        disjointset bob(n+1);
        for(auto i:edges)
        {
            if(i[0]==3)
            {
                int y=0,z=0;
                if(alice.findUpar(i[1])!=alice.findUpar(i[2])){
                    alice.unionbyrank(i[1],i[2]);
                    y=1;
                }
                if(bob.findUpar(i[1])!=bob.findUpar(i[2])){
                    bob.unionbyrank(i[1],i[2]);
                    z=1;
                }
                if(y==1 || z==1)
                {
                    sum++;
                }

            }
        }

  for(auto i:edges)
        {
            if(i[0]==1)
            {
                if(alice.findUpar(i[1])!=alice.findUpar(i[2])){
                    alice.unionbyrank(i[1],i[2]);
                    sum++;
                }
            }
            if(i[0]==2){
                if(bob.findUpar(i[1])!=bob.findUpar(i[2])){
                    bob.unionbyrank(i[1],i[2]);
                    sum++;
                }
            }
        }

        int a=0,b=0;
        for(int i=1;i<=n;i++)
        {
           if(alice.findUpar(i)==i)
           {
            a++;
           }
           if(bob.findUpar(i)==i)
           {
            b++;
           }

        }
        if(a>1 || b>1)
        {
            return  -1;
        }
        
        return m-sum;
    }
};
