class Solution {
public:

    int solve(vector<int> &stalls,int &n,int m,int count)
    {
        int last=stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-last>=m)
            {
                last=stalls[i];
                count--;
            }
            if(count==0)
            {
                return true;
            }
            
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        int e=stalls[n-1]-stalls[0];
        int i=1;
        while(i<=e)
        {
            int m=(i+e)/2;
            // cout<<m<<endl;
            if(solve(stalls,n,m,k-1))
            {
                i=m+1;
            }
            else
            {
                e=m-1;
            }
        }
        return e;
    }
};
