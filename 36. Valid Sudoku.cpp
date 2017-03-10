//36. Valid Sudoku
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> exist(9, false);

        //check if rows and column have duplicates
        for (int i = 0; i < 9; i++)
        {
            //check every row
            fill(exist.begin(), exist.end(), false);
            for (int j = 0; j < 9; j++)
                if (!check_cell(board[i][j], exist))
                    return false;
         //check every column
            fill(exist.begin(), exist.end(), false);
            for (int j = 0; j < 9; j++)
                if (!check_cell(board[j][i], exist))
                    return false;
        }
        //check if 9-suboxes have duplicates
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                //check every subboxes
                fill(exist.begin(), exist.end(), false);
                for (int sub_i = i * 3; sub_i < i * 3 + 3; sub_i++)
                {
                    for (int sub_j = j * 3; sub_j < j * 3 + 3; sub_j++)
                    {
                        if (!check_cell(board[sub_i][sub_j], exist))
                            return false;
                    }
                }
            }
        }
        return true;
    }
private:
    bool check_cell(char ch, vector<bool>& exist)
    {
        if (ch == '.')
            return true;
        else if (exist[ch - '1'])
            return false;
        else
            return exist[ch - '1'] = true;
    }
};