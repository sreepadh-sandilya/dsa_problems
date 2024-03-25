class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int solve(int nums[], int target,int i,int j)
    {
        while(i<=j)
        {
            int m=(i+j)/2;
            if(nums[m]<target)
            {
                i=m+1;
            }
            else
            {
                j=m-1;
            }

        }
        return i;
    }	
	int count(int nums[], int n, int target) {
	    // code here
	   int l=solve(nums,target,0,n-1);
        int h=solve(nums,target+1,0,n-1)-1;
        if(l<n && nums[l]==target)
        {
           return h-l+1;
        }
        return 0;
	}
};
