class Solution {
public:
    int minBitFlips(int start, int goal) {
        int sum=(start^goal);
        int count=0;
        while(sum)
        {
            if(sum%2!=0)
            {
               count++;
            }
            sum/=2;
        }

        return count;
        
    }
};
