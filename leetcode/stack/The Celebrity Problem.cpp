
// brute force
class Solution 
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        vector<int> mp1(n, 0);
        vector<int> mp2(n, 0);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j])
                {
                    mp1[j]++;
                    mp2[i]++;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (mp1[i] == n - 1 && mp2[i] == 0)
            {
                return i;
            }
        }

        return -1;
    }
};
