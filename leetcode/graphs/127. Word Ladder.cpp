class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        int n=wordList.size(),ans=0;
        vector<int>vis(n,-1);
        while(!q.empty())
        {
            int siz=q.size();
            for(int k=0;k<siz;k++){
                string s=q.front();
                if(s==endWord)
                {
                    return ans+1;
                }
                q.pop();
                for(int i=0;i<n;i++)
                {
                    if(vis[i]==-1)
                    {
                        int sum=0;
                        for(int j=0;j<beginWord.size();j++)
                        {
                        if(s[j]!=wordList[i][j])
                        {
                            sum++;
                        }

                        }
                        if(sum==1)
                        {
                            q.push(wordList[i]);
                            vis[i]=1;
                        }
                    }
                }
            }
            ans++;

        }

        return 0;
    }
};


// optimized:
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        int n=wordList.size(),ans=0;
        vector<int>vis(n,-1);
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty())
        {
            int siz=q.size();
            for(int k=0;k<siz;k++){
                string s=q.front();
                if(s==endWord)
                {
                    return ans+1;
                }
                q.pop();
                for(int i=0;i<s.size();i++){
                    string o=s;
                    for(char ch='a';ch<='z';ch++)
                    {
                        o[i]=ch;
                        if(st.find(o)!=st.end())
                        {
                            st.erase(o);
                            q.push(o);
                        }

                    }
                }
                
            }
            ans++;

        }

        return 0;
    }
};
