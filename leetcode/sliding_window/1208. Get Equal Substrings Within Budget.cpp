class Solution {
public:
    
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int j=0;
        int sum=0;
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            
            sum+=abs(s[i]-t[i]);
            // cout<<abs(s[i]-t[i])<<" "<<sum<<endl;
            while(sum>maxCost)
            {
                sum-=abs(s[j]-t[j]);
                j++;
            }
            // cout<<i<<" "<<j<<endl;

            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};
