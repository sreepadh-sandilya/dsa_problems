class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1,d=1,t=0;
        while(t<time)
        {
           if(d==1)
           {
            i++;
            
           }
           else
           {
            i--;
           }
           t++;
           if(i==n || i==1)
           {
            d*=-1;
           }
        //    cout<<i<<" "<<t<<endl;
        }
        return i;
    }
};
