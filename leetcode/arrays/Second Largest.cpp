class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int a=INT_MIN,b=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        if(a==INT_MIN)
	        {
	            a=max(a,arr[i]);
	        }
	        else
	        {
	            if(arr[i]<=a)
	            {
	                if(a!=arr[i]){
	                b=max(b,arr[i]);
	                }
	            }
	            else
	            {
	                b=a;
	                a=arr[i];
	                
	            }
	        }
	    }
	    if(b==INT_MIN)
	    {
	        return -1;
	    }
	    return b;
	}
};
