class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        if(arr[0]-1>=k)
        {
           return k;
        }
        if(arr[n-1]-n<k)
        {
          return arr[n-1]+k-(arr[n-1]-n);
        }
        int i=1,j=n-2;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(arr[m]-(m+1)<k)
            {
                i=m+1;
            }
            else
            {
                j=m-1;
            }
        }
        
        return arr[j]+k-(arr[j]-(j+1));
    }
};
