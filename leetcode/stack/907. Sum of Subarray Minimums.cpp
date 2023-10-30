
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod= (1e9+7);
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;
        stack<int>st1;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                right[i]=n;
                st.push(i);
                continue;
            }

            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }

            if(!st.empty())
            {
                right[i]=st.top();
            }
            else
            {
                right[i]=n;
            }
            st.push(i);
        }

        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                left[i]=-1;
                st1.push(i);
                continue;
            }

            while(!st1.empty() && arr[i]<arr[st1.top()])
            {
                st1.pop();
            }
            if(!st1.empty())
            {
                left[i]=st1.top();
            }
            else
            {
                left[i]=-1;
            }
            st1.push(i);
        }

        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum =(sum+ (long long)(right[i]-i)*(i-left[i])*arr[i])%mod;
            
        }

        return sum;
    }
};

