//51. N-Queens
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <iterator>
using namespace std;

//time O(n! * n) space O(n)
//just dfs
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string> > result;
        vector<int> flag(n, -1);
        dfs(flag, result, 0);
        return result;
    }

private:
    void dfs(vector<int>& flag, vector< vector<string> >& result, int row)
    {
        if (row == flag.size())
        {
            vector<string> solution;
            for (int i = 0; i < row; i++)
            {
                string s(row, '.');
                for (int j = 0; j < row; j++)
                    if (flag[i] == j)
                        s[j] = 'Q';
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }

        for (int i = 0; i < flag.size(); i++)
        {
            if (!valid_cell(flag, row, i))
                continue;

            flag[row] = i;
            dfs(flag, result, row + 1);
            flag[row] = -1;
        }
    }

    bool valid_cell(const vector<int>& flag, int row, int column)
    {
        for (int i = 0; i < row; i++)
        {
            if (flag[i] == column)
                return false;
            if (abs(row - i) == abs(column - flag[i]))
                return false;
        }
        return true;
    }
};

//time O(n!) space O(n)
//dfs and prune
class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        //initialize prune variables
        column = vector<bool>(n, false);
        diagonal1 = vector<bool>(2 * n - 1, false);
        diagonal2 = vector<bool>(2 * n - 1, false);

        vector< vector<string> > result;
        vector<int> flag(n, -1);
        dfs(flag, result, 0);
        return result;
    }

private:
    //prune variable
    vector<bool> column;
    vector<bool> diagonal1; //diagonal like  /
    vector<bool> diagonal2;//diagonal like   \

    void dfs(vector<int>& flag, vector< vector<string> >& result, int row)
    {
        if (row == flag.size())
        {
            vector<string> solution;
            for (int i = 0; i < row; i++)
            {
                string s(row, '.');
                for (int j = 0; j < row; j++)
                    if (flag[i] == j)
                        s[j] = 'Q';
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }

        for (int i = 0; i < flag.size(); i++)
        {
            //prune
            if (column[i] || diagonal1[row + i] || diagonal2[row + (flag.size() - 1 - i)])
                continue;

            column[i] = diagonal1[row + i] = diagonal2[row + (flag.size() - 1 - i)] = true;
            flag[row] = i;
            dfs(flag, result, row + 1);
            flag[row] = -1;
            column[i] = diagonal1[row + i] = diagonal2[row + (flag.size() - 1 - i)] = false;
        }
    }
};

int main()
{
    Solution2 s;

    for (auto& board : s.solveNQueens(8))
    {
        copy(board.begin(), board.end(), ostream_iterator<string>(cout, "\n"));
        cout << endl;
    }

}