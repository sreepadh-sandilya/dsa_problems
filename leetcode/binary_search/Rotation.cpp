class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    int ans=INT_MAX,k=-1;
        int i=0,j=n-1;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(nums[i]<=nums[m])
            {
                // ans=min(ans,nums[i]);
                if(ans>nums[i])
                {
                    ans=nums[i];
                    k=i;
                }
                i=m+1;
            }
            else
            {
                // ans=min(ans,nums[m]);
                if(ans>nums[m])
                {
                    ans=nums[m];
                    k=m;
                }
                j=m-1;
            }

        }
        return k;
    
    
	}

};
