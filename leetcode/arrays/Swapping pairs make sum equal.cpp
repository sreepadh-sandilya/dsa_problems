class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here

        int sum1=0,sum2=0;
        sort(a,a+n);
        sort(b,b+m);
        for(int i=0;i<n;i++)
        {
            sum1+=a[i];
        }
        for(int i=0;i<m;i++)
        {
            sum2+=b[i];
        }
        int i=0,j=0;
        if(sum1==sum2)
        {
            return 1;
        }
        while(i<n && j<m)
        {
            int temp1=sum1 + (b[j]-a[i]);
            int temp2=sum2+(a[i]-b[j]);
            if(temp1==temp2)
            {
                return 1;
            }
            if(temp1>temp2)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        return -1;
    }
};
