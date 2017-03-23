//62. Unique Paths
//dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> board(m + 1, vector<int>(n + 1, 0));
        board[0][1] = 1;
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
                board[i][j] = board[i][j - 1] + board[i - 1][j];
        }
        return board[m][n];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;

    return 0;
}