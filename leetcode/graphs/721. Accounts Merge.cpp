
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        unordered_map<string,int>mp;
        
        int n=acc.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<acc[i].size();j++)
            {
                if(mp.count(acc[i][j])==0)
                {
                    mp[acc[i][j]]=i;
                }
                else
                {
                    ds.unionByRank(mp[acc[i][j]],i);
                }
            }
        }

        vector<vector<string>>mer(n);
        vector<vector<string>>ans;
        for(auto i:mp)
        {
            int p=ds.findUPar(i.second);
            mer[p].push_back(i.first);
            
        }
        for(int i=0;i<mer.size();i++)
        {
            if(mer[i].empty())
            {
                continue;
            }
            sort(mer[i].begin(),mer[i].end());
            vector<string>temp;
            temp.push_back(acc[i][0]);
            for(int j=0;j<mer[i].size();j++)
            {
              temp.push_back(mer[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
