#include <bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    // Write your code here
    int n=s.length(),sum=0,sum1=0,f=0,j=0;
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==0)
            {
                mp[s[i]]++;
                f++;
            }
            else
            {
                mp[s[i]]++;
            }
            while(f>k && j<i)
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    f--;
                }
                j++;
                
            }
            sum=max(sum,i-j+1);
            
        }
        return sum;
}


