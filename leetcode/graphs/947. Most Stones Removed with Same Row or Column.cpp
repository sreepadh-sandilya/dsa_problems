
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
    int removeStones(vector<vector<int>>& stones) {
    /
    int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        disjointset ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUpar(it.first) == it.first) {
                cnt++;
            }
        }
        return stones.size() - cnt;
    }
};
