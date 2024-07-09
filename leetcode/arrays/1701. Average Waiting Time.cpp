class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long sum=0,w=0,n=customers.size();
        sum+=customers[0][0]+customers[0][1];
        w=sum-customers[0][0];
        for(int i=1;i<n;i++)
        {
           if(customers[i][0]<sum){ 
           sum+=customers[i][1];
           }
           else
           {
            sum=customers[i][0]+customers[i][1];
           }
           w+=sum-customers[i][0];
        }
        return (double)w/n;
    }
};
