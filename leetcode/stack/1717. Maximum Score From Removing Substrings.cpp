class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int sum=0;
        string top,bot;
        int top_sc,bot_sc;
        if(y>x)
        {
            top="ba";
            bot="ab";
            top_sc=y;
            bot_sc=x;
        }
        else
        {
            top="ab";
            bot="ba";
            top_sc=x;
            bot_sc=y;
        }

        stack<char>st;
        for(auto i:s)
        {
            if(i==top[1] && !st.empty() && st.top()==top[0])
            {
                sum+=top_sc;
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        
        s="";
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        for(auto i:s)
        {
            if(i==bot[1] && !st.empty() && st.top()==bot[0]){
                sum+=bot_sc;
                st.pop();
            }
            else{
                st.push(i);
            }
        }

        return sum;
    }
};
