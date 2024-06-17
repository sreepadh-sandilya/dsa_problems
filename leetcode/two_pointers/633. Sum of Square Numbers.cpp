class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0,j=sqrt(c);
        while(i<=j)
        {
            long long prod=i*i + (long long)j*j;
            if(prod>c){
                j--;
            }
            else if(prod<c){
                i++;
            }
            else{
                return true;

            }
        }
        return false;
    }
};
