class Solution {
public:
    static bool comp(string a,string b)
    {
        return b.length()>a.length();
    }
    int lcs(string &a,string &b)
    {
        int j=0;
        int n=a.length();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[j])
            {
              sum++;
              j++;
            }
        }
        return sum;

    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        sort(words.begin(),words.end(),comp);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {

                if(words[i].size()-1==words[j].size() && lcs(words[i],words[j])==words[i].length()-1)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
            int a=-1;
    for(auto i:dp)
    {
       a=max(a,i);
    }
    return a;
    }

};

