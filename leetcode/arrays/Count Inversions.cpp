class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long s,long long m,long long e,long long &ans)
    {
        long long len1=m-s+1;
        long long len2=e-m;
        long long* first=new long long[len1];
        long long* second=new long long[len2];
        long long main=s;
        for(long long i=0;i<len1;i++)
        {
            first[i]=arr[main++];
        }
        for(long long i=0;i<len2;i++)
        {
            second[i]=arr[main++];
        }
        main=s;
        long long ind1=0,ind2=0;
        while(ind1<len1 && ind2<len2){
            if(first[ind1]>second[ind2])
            {
                ans+=len1-ind1;
                arr[main++]=second[ind2++];
                
            }
            else
            {
                arr[main++]=first[ind1++];
            }
        }
        while(ind1<len1)
        {
            arr[main++]=first[ind1++];
        }
        while(ind2<len2)
        {
            arr[main++]=second[ind2++];
        }
    }
    void mergesort(long long arr[], long long s,long long e,long long &ans)
    {
        if(s>=e)
        {
            return;
        }
        long long m=(s+e)/2;
        mergesort(arr,s,m,ans);
        mergesort(arr,m+1,e,ans);
        merge(arr,s,m,e,ans);
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long ans=0;
        mergesort(arr,0,n-1,ans);
        return ans;
        
    }

};
