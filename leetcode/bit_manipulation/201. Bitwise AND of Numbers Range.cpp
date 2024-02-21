class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left && right)
        {
            if(left==right)
            {
                break;
            }
            left=left>>1;
            right=right>>1;
            count++;

        }
        //  cout<<left<<" "<<count<<endl;
        if(left==right)
        {
            while(count--)
            {
                left=left<<1;
            }
            return left;
        }
        return 0;
    }
};
