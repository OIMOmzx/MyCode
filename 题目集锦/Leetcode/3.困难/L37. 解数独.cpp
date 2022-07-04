#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution 
{
public:
    void solveSudoku(vector<vector<char> > &board) 
	{
		backtracking(board);
    }
	bool backtracking(vector<vector<char> > &board)	
		{
			for(int i = 0; i <= 8; i++)
			{
				for(int j = 0; j <= 8; j++)
				{
					if(board[i][j] != '.') continue;
					for(char ch = '1'; ch <= '9'; ch++)
					{
						if(isValid(i, j, board, ch) == 1) 
						{
							board[i][j] = ch;
							if(backtracking(board) )return 1;
							board[i][j] = '.';
						}

					}
					return 0;
				}
			}
			return 1;
		}
private:	
		int isValid(int row, int col, vector<vector<char> >&board, char ch)
		{
			for(int i = 0; i <= 8; i++)
			{
				if(ch == board[row][i]) return 0;
				
			}
			for(int j = 0; j <= 8; j++)
			{
				if(ch == board[j][col]) return 0;
				
			}
			int startrow = (row / 3 )* 3;
			int startcol = (col / 3 )* 3;
			for(int i = startrow; i <= startrow + 2; i++)
			{
				for(int j = startcol; j <= startcol + 2; j++)
				{
					if(ch == board[i][j]) return 0;
					
				}
			}
			return 1;			
		}
	
};