class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,-1));
        for(auto i:edges)
        {
            matrix[i[0]][i[1]]=i[2];
            matrix[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    matrix[i][j]=0;
                }
                else if(matrix[i][j]==-1)
                {
                    matrix[i][j]=100000;
                }
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int index=n+1,value=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                
                if(matrix[i][j]<=distanceThreshold){
                    sum++;
                }
                
            }
            
            if(sum<value)
                {
                    value=sum;
                    index=i;
                }
        }
        return index;
        
    }
};
