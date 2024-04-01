class Solution{
public:
    int solve(vector<int>v,int m)
    {
        int i=0,j=m-1;
        int ans=INT_MAX;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(v[m]==0)
            {
                i=m+1;
            }
            else{
                ans=min(m,ans);
                j=m-1;
            }
        }
        return m-ans;
        
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int sum=0,k=-1;
	    for(int i=0;i<n;i++)
	    {
	        int d=solve(arr[i],m);
	        if(d>sum)
	        {
	            sum=d;
	            k=i;
	        }
	    }
	    return k;
	}

};
