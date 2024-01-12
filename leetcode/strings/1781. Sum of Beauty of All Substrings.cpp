class Solution {
public:
    int beautySum(string s) {
        
        int n=s.length(),maxi=INT_MIN,mini=INT_MAX,sum=0;
        
        for(int i=0;i<n;i++)
        {

            vector<int>v(26,0);
            

            for(int j=i;j<n;j++)
            {
                maxi=INT_MIN,mini=INT_MAX;
              v[s[j]-'a']++;
              for(auto k:v)
              {
                  if(k>0){
                  mini=min(mini,k);
                  maxi=max(maxi,k);
                  }
              }
\
              sum+=maxi-mini;

        }
        return sum;
        
    }
};
