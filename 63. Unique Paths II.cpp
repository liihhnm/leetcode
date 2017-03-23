//63. Unique Paths II
//dp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
            return 0;

        vector<vector<int>> board(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
            copy(obstacleGrid[i].begin(), obstacleGrid[i].end(), board[i + 1].begin() + 1);

        board[0][1] = 1;
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (board[i][j])
                    board[i][j] = 0;
                else
                    board[i][j] = board[i][j - 1] + board[i - 1][j];
            }
        }
        return board[m][n];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> test = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0} };
    cout << s.uniquePathsWithObstacles(test) << endl;

    return 0;
}