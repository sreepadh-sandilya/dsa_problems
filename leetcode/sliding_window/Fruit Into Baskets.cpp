class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        unordered_map<int,int>mp;
        int sum=0,k=0,j=0;
        for(int i=0;i<n;i++)
        {
            if(mp[fruits[i]]==0)
            {
                
                k++;
            }
            while(k>2)
            {
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0)
                {
                    k--;
                }
                j++;
            }
            mp[fruits[i]]++;
            sum=max(sum,i-j+1);
            
        }
        return sum;
        
    }
};
