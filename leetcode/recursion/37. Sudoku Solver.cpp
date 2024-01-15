class Solution {
public:

    bool isvalid(vector<vector<char>>& board,int row,int col,char k)
    {
        
        for(int i=0;i<=8;i++)
        {
            if(board[i][col]==k)
            {
                return false;
            }
            if(board[row][i]==k)
            {
                return false;
            }

        }
        int rc,cc;
        if(row<=2)
        {
            rc=0;
        }
        else if(row<=5)
        {
            rc=3;
        }
        else
        {
            rc=6;
        }
        if(col<=2)
        {
            cc=0;
        }
        else if(col<=5)
        {
            cc=3;
        }
        else
        {
            cc=6;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i+rc][j+cc]==k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>&board)
    {

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isvalid(board,i,j,k))
                        {
                            board[i][j]=k;
                            if(solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]='.';
                            }
                        }
                    }
                   return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


