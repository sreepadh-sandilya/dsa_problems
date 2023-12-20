class Solution {
public:
    bool issafe(int row,int col,vector<string>b,int n)
    {
        int r=row,c=col;
        while(r>=0)
        {
            if(b[col][r]=='Q')
            {
                return false;
            }
            r--;
        }
        r=row;
        while(c>=0)
        {
            if(b[c][row]=='Q')
            {
                return false;
            }
            c--;
        }
        c=col;
        while(r>=0 && c>=0)
        {
           if(b[c][r]=='Q')
           {
               return false;
           }
           c--;
           r--;
        }
        c=col;
        r=row;
        while(r<n && c>=0)
        {
            if(b[c][r]=='Q')
            {
                return false;
            }
            c--;
            r++;
        }
        return true;

    }
    void solve(int col,vector<string>&b,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(b);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(b[row][col]=='.' && issafe(row,col,b,n))
            {
                b[col][row]='Q';
                solve(col+1,b,ans,n);
                b[col][row]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<bool>>v(n,vector<bool>(false,n));
        string s(n,'.');
        vector<string>b(n);
        for(int i=0;i<n;i++)
        {
           b[i]=s;
        }
        solve(0,b,ans,n);
        return ans;

        
    }
};
