class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool solve(int A[],int n,int count,int mid)
    {
        int sum=0,c=1;
        for(int i=0;i<n;i++)
        {
            if(sum+A[i]<=mid)
            {
                sum+=A[i];
            }
            else
            {
                if(A[i]>mid)
                {
                    return false;
                }
                sum=A[i];
                c++;
            }
            
            
        }
        
        if(c>count)
        {
            return true;
        }
        return false;
    }
    int findPages(int A[], int n, int m) 
    {
        //code here
        if(m>n)
        {
            return -1;
        }
        int total=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            total+=A[i];
            maxi=max(maxi,A[i]);
        }
        int j=total,i=maxi;
        while(i<=j)
        {
            int mid=(i+j)/2;
            cout<<mid<<endl;
            if(solve(A,n,m,mid))
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return i;
    }
};
