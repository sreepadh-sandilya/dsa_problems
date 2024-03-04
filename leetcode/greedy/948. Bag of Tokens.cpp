class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,n=tokens.size();
        int sum=0,maxi=0;
        while(i<=j)
        {

            while(i<n && power>=tokens[i])
            {
                power-=tokens[i++];
                sum++;
                maxi=max(sum,maxi);
            }
            if(sum>0 && i<=j)
            {
               power+=tokens[j--];
               sum--;
            }
            else
            {
                break;
            }



        }
        return maxi;

        
    }
};
