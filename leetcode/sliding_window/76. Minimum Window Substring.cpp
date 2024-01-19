class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        for(auto i:t)
        {
            mp[i]++;
        }

        int count=mp.size(),sum=INT_MAX,n=s.length(),j=0,start=INT_MAX;
        for(int i=0;i<n;i++)
        {

            if(mp.find(s[i])!=mp.end())
            {
               mp[s[i]]--;
               if(mp[s[i]]==0)
               {
                   count--;
                   if(count==0)
                   {
                      while(count==0)
                      {
                          if(mp.find(s[j])!=mp.end()){
                            mp[s[j]]++;
                            if(mp[s[j]]>0)
                            {
                                count++;
                            }
                            if(i-j+1<sum)
                            {
                                sum=i-j+1;
                                start=j;
                            }
                          }
                          j++;
                          
                      }
                      
                   }
               }
            }
        }

        if(start==INT_MAX)
        {
            return "";
        }
        return s.substr(start,sum);
    }
};


