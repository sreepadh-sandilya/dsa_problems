class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        long long t=0,wt=0;
        int n=bt.size();
        for(int i=1;i<n;i++){
            t+=bt[i-1];
            wt+=t;
        }
        return (wt/n);
    }
};
