class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),max1=-1,max2=-1,a=n,b=n;
        vector<int>right(n,0);
        vector<int>left(n,0);
        stack<int>l;
        stack<int>r;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                right[i]=n;
                r.push(i);

            }
            else
            {
                while(!r.empty() && height[i]>=height[r.top()])
                {
                    r.pop();
                }
                if(!r.empty())
                {
                    right[i]=r.top();
                    

                }
                else
                {
                    right[i]=n;
                }
                if(!r.empty() && height[r.top()]<height[i])
                {
                  r.push(i);
                }
                else if(r.empty())
                {
                    r.push(i);
                }
            }

        }

        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                left[i]=-1;
                l.push(i);
            }
            else
            {
                while(!l.empty() && height[i]>=height[l.top()])
                {
                    l.pop();
                }
                if(!l.empty())
                {
                    left[i]=l.top();
                }
                else
                {
                    left[i]=-1;
                }
                if(!l.empty() && height[l.top()]<height[i]){
                l.push(i);
                }
                else if(l.empty())
                {
                    l.push(i);
                }
            }
        }

        // for(auto i:left)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        // for(auto i:right)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        int sum=0;
        for(int i=0;i<n;i++)
        {
           if(left[i]!=-1 && right[i]!=n)
           {
            //    cout<<min(height[right[i]],height[left[i]])-height[i]<<" "<<i<<endl;
               sum+= min(height[right[i]],height[left[i]])-height[i];
           }
        }

        return sum;
        
    }
};
