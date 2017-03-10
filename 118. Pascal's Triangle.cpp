//118. Pascal's Triangle

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return vector<vector<int>>();
        vector<vector<int>> result;
        vector<int> previous(numRows, 0);
        previous[0] = 1;
        for (int i = 1; i <= numRows; i++)
        {
            for (int j = i - 1; j > 0; j--)
                previous[j] += previous[j - 1];
            result.push_back(vector<int>(previous.begin(), previous.begin() + i));
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (auto i = 0; i<numRows; ++i)
        {
            res.push_back(vector<int>(i + 1, 1));
            for (auto j = 1; j<i; ++j) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        return res;
    }
};