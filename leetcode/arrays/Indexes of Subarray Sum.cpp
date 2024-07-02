class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
        int i=0,j=0;
        long long sum=0;
        vector<int>ans;
        for(i=0;i<n;i++)
        {
            sum+=arr[i];
            while(sum>s && i>j){
                sum-=arr[j];
                j++;
            }
            if(sum==s)
            {
                ans.push_back(j+1);
                ans.push_back(i+1);
                return ans;
            }
        }

        ans.push_back(-1);
        return ans;
    }
};
