class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int a=i;
            while(a){
                if(a%10==4){
                    sum++;
                    break;
                }
                a=a/10;
            }
        }
        return sum;
    }
};
