class Solution {
public:
    int num=26;
    int inf=INT_MAX;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>graph(num,vector<int>(num,inf));
        for(int i=0;i<num;i++)
        {
            graph[i][i]=0;
        }
        int n=original.size();
        for(int i=0;i<n;i++)
        {
            graph[original[i]-'a'][changed[i]-'a']=min(graph[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
        for(int k=0;k<num;k++)
        {
            for(int i=0;i<num;i++)
            {
                for(int j=0;j<num;j++)
                {
                    if(graph[i][k]<inf && graph[k][j]<inf)
                    {
                       graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                    }
                }
            }
        }

        long long sum=0;
        for(int i=0;i<source.length();i++)
        {
            if(graph[source[i]-'a'][target[i]-'a']==inf)
            {
                return -1;
            }
            sum+=(long long)graph[source[i]-'a'][target[i]-'a'];
        }
        return sum;
    }
};
