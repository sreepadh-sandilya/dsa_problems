class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j)
        {
           if(s[i]!=s[j])
           {
               return j-i+1;
           }
           char c=s[i];
           while(i<=j && s[i]==c)
           {
               i++;
           }
           while(i<=j && s[j]==c)
           {
               j--;
           }

        }
        if(i==j)
        {
            return 1;
        }
        return 0;
    }
};
