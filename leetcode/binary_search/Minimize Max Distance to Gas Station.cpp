class Solution {
  public:
   int solve(vector<int> &stations, int k,long double mid)
   {
       int cnt=0;
       for(int i=1;i<stations.size();i++)
       {
           int p=((stations[i]-stations[i-1])/mid);
           if((stations[i]-stations[i-1])/mid == p*mid)
           {
               p--;
           }
           cnt+=p;
       }
       return cnt;
   }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        long double low=0;
        long double high=0;
        for(auto i: stations)
        {
            if(high<i)
            {
                high=i;
            }
        }
        
        long double diff=1e-6;
        while(high-low>diff)
        {
            long double mid=(high+low)/2.0;
            int cnt=solve(stations,k,mid);
            if(cnt>k)
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
        }
        return high;
    }
};
