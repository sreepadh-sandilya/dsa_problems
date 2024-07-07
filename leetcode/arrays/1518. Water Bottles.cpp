class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        int empty=numBottles,full=0;
        while(true)
        {
          full=empty/numExchange;
          empty=empty-(empty/numExchange)*numExchange+full;
          sum+=full;
          if(empty<numExchange){
            break;
          }
          
        }
        return sum;

    }
};
