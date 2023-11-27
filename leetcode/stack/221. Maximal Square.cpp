class Solution {
public:
    int solve(vector<char>v,int n,int m,vector<int>&ans)
    {
       for(int i=0;i<m;i++)
       {
           if(v[i]=='0')
           {
               ans[i]=0;
           }
           else
           {
               ans[i]+=1;
           }
       }
       
       stack<int>st1;
       stack<int>st2;
       vector<int>left(m,0);
       vector<int>right(m,0);
       for(int i=m-1;i>=0;i--)
       {
           if(i==m-1)
           {
              left[i]=m;
              
           }
           else
           {
               while(!st1.empty() && ans[i]<=ans[st1.top()])
               {
                   st1.pop();
               }
               if(!st1.empty())
               {
                   left[i]=st1.top();
               }
               else
               {
                   left[i]=m;
               }
               
           }
           st1.push(i);
       }

       for(int i=0;i<m;i++)
       {
           if(i==0)
           {
               right[i]=-1;
           }
           else
           {
               while(!st2.empty() && ans[i]<=ans[st2.top()])
               {
                   st2.pop();
               }
               if(!st2.empty())
               {
                   right[i]=st2.top();
               }
               else
               {
                   right[i]=-1;
               }
               
           }
           st2.push(i);
       }
       for(auto i:left)
       {
           cout<<i<<" ";
       }
       cout<<endl;
       for(auto i:right)
       {
           cout<<i<<" ";
       }
       cout<<endl;
       int k=0;
       for(int i=0;i<m;i++)
       {
         k=max(k,min(left[i]-right[i]-1,ans[i]));
       }
    return k;

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans(m,0);
        int k=0;
        for(int i=0;i<n;i++)
        {
           k=max(k,solve(matrix[i],n,m,ans));
        }
        return k*k;
        
    }
};
