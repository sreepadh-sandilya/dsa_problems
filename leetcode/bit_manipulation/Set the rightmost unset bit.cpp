class Solution
{
public:
    int setBit(int n)
    {
        // Write Your Code here
        int c=0;
        int k=n;
        while(k!=0)
        {
            if((k & 1)==0)
            {
                return (n | (1<<c));
            }
            c++;
            k= k>>1;
           
        }
        return n;
        
    }
};
