class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<char>>v(k);
        for(int i=0;i<n-1;i++)
        {
            int j=0;
            int s=min(dict[i].length(),dict[i+1].length());
            while(j<s && dict[i][j]==dict[i+1][j])
            {
                j++;
                
            }
            if(j!=s)
            {
                v[dict[i][j]-'a'].push_back(dict[i+1][j]);
            }
        }
        queue<char>q;
        string s="";
        vector<int>ind(k,0);
        for(auto i:v)
        {
            for(auto j:i)
            {
                ind[j-'a']++;
            }
        }
        
        for(int i=0;i<k;i++)
        {
            if(ind[i]==0)
            {
                q.push(i+'a');
            }
        }
        
        while(!q.empty())
        {
            char c=q.front();
            q.pop();
            s+=c;
            for(auto i:v[c-'a'])
            {
                ind[i-'a']--;
                if(ind[i-'a']==0)
                {
                    q.push(i);
                }
            }
        }
        
        return s;
        
        
    }
};
