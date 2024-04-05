class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<=n-1;i++)
        {
            if(ans.empty())
            {
                ans.push_back(s[i]);
                continue;
            }
          if(ans.back()-'a'==s[i]-'A' || ans.back()-'A'==s[i]-'a')
          {
            if(!ans.empty())
            {
                ans.pop_back();
            }
            
          }
          else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
