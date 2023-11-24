class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        int sum=0,j=0;
        for(int i=0;i<n;i++)
        {
            if(mp.count(s[i])==0 || mp[s[i]]<j)
            {
                sum=max(sum,i-j+1);
                mp[s[i]]=i;

            }
            else
            {
                j=mp[s[i]]+1;
                mp[s[i]]=i;
            }
        }
        return sum;
        
    }
};
