class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int l=0;
       int r=n-1,m=0;
       while(l<r)
       {
           m=(l+r)/2;
           if(arr[m+1]>=arr[m])
           {
               l=m+1;
           }
           else
           {
               r=m;
           }
       }
       
       return l;
    }
};
