class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int sum=0;
        for(auto i:arr)
        {
            if(i%2!=0)
            {
                sum++;
            }
            else
            {
                sum=0;
            }
            if(sum==3)
            {
                return true;
            }
        }
        return false;
    }
};
