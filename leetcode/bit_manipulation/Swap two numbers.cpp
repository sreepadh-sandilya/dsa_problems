class Solution{   
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        a=a^b;
        b=a^b;   // b=(a^b^b)=a
        a=a^b;   // a=(a^a^b)=b
        pair<int,int>temp={a,b};
        return temp;
    }
};
