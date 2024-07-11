class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        vector<char>res;
        for(auto i:s)
        {
            if(i=='(')
            {
                st.push(res.size());
            }
            else if(i==')')
            {
                int start_ind=st.top();
                st.pop();
                reverse(res.begin()+start_ind,res.end());
            }
            else
            {
                res.push_back(i);
            }
        }

        return string(res.begin(),res.end());
    }
};
