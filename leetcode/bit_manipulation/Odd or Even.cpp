class Solution{   
public:
    string oddEven(int n){
        // code here 
        if((n & 1))
        {
            return "odd";
        }
        else
        {
            return "even";
        }
    }
};
