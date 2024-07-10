class Solution {
public:
    int minOperations(vector<string>& logs) {
        int sum=0;
        for(auto i:logs)
        {
            if(i.length()==2)
            {
                if(i[0]=='.')
                {
                    continue;
                }
                else
                {
                    sum++;
                }
            }
            else if(i[0]=='.')
            {
                sum--;
                if(sum<0)
                {
                    sum=0;
                }
            }
            else
            {
                sum++;
            }
        }

        return sum;
        
    }
};
