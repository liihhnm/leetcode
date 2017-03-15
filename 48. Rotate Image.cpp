//48. Rotate Image
#include <vector>
#include <algorithm>

using namespace std;

//按水平中线翻转 再对角线翻转
//也可以先反对角线翻转 再水平翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int size = matrix.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};