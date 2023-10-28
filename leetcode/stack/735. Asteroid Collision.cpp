class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        int n=as.size();
      vector<int>ans;
      stack<int>st;
      for(int i=n-1;i>=0;i--)
      {
          if(st.empty())
          {
              st.push(as[i]);
              continue;
          }

          if(as[i]>0)
          {
              int x=as[i];
              while(!st.empty() && st.top()<0 && x>abs(st.top()))
              {
                  st.pop();
              }
              if(!st.empty() && st.top()<0)
              {
                  if(x==abs(st.top()))
                  {
                      st.pop();
                  }

              }
              else{
                  st.push(x);
              }
          }
          else
          {
              st.push(as[i]);
          }


      }

      while(!st.empty())
      {
          ans.push_back(st.top());
          st.pop();
          
      }

      return ans;
    }
};
