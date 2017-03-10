//37. Sudoku Solver
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

//O(9 ^ 4)
//use depth first search
//for every empty cell, try to fill 0 - 9. 
//and when valid then find next empty cell recursively
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        sudoku_helper(board);
    }

private:
    bool sudoku_helper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 0; k < 9; k++)
                    {
                        board[i][j] = '1' + k;
                        if (valid_cell(board, i, j) && sudoku_helper(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool valid_cell(const vector< vector<char> >& board, int x, int y)
    {
        //check row
        for (int i = 0; i < 9; i++)
            if (i != y && board[x][i] == board[x][y])
                return false;
        //check column
        for (int i = 0; i < 9; i++)
            if (i != x && board[i][y] == board[x][y])
                return false;
        //check suboxes
        for (int i = (x / 3) * 3; i < (x / 3 ) * 3 + 3; i++)
        {
            for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
                if ((i != x || j != y) && (board[i][j] == board[x][y]))
                    return false;
        }
        return true;
    }
};

void print_table(const vector< vector<char> > board)
{
    for (auto& row : board)
    {
        copy(row.begin(), row.end(), ostream_iterator<char>(cout, " "));
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector< vector<char> > board(9);
    vector<string> origin_data = {
        "..9748...",
        "7........",
        ".2.1.9...",
        "..7...24.",
        ".64.1.59.",
        ".98...3..",
        "...8.3.2.",
        "........6",
        "...2759.."
    };
    for (int i = 0; i < 9; i++)
        copy(origin_data[i].begin(), origin_data[i].end(), back_inserter(board[i]));

    print_table(board);
    Solution s;
    s.solveSudoku(board);
    print_table(board);
}