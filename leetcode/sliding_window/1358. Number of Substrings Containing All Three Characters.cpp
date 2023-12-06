class Solution {
public:
    int numberOfSubstrings(string s) {
        long long n=s.length(),j=0,sum=0;
        long long total=n*(n+1)/2;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1 && j<i)
            {
                mp[s[j]]--;
                j++;
            }
            if(mp['a']==0 || mp['b']==0 || mp['c']==0)
            {
                sum+=i-j+1;
            }

        }
        return total-sum;
        
    }
};
