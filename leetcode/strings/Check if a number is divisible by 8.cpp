class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n=s.length();
        int a=0;
        for(int i=n-1;i>=0 && i>=n-3;i--)
        {
            a+=(s[i]-'0')*pow(10,n-1-i);
        }
        if(a%8==0)
        {
            return 1;
        }
        return -1;
    }
};
