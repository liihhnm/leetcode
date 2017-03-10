//119. Pascal's Triangle II

#include <vector>
#include <iostream>

using namespace std;

//build Pascal's Triangle row by row
//too slow!!!
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> previous({ 1 });
        if (rowIndex == 0)
            return previous;
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> next_row;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    next_row.push_back(previous[j]);
                else if (j == i)
                    next_row.push_back(previous[j - 1]);
                else
                    next_row.push_back(previous[j - 1] + previous[j]);
            }
            previous = next_row;
        }
        return previous;
    }
};

//add from right to left
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for (int i = 0; i < rowIndex; i++)
        {
            for (int j = rowIndex; j >= 1; j--)
                result[j] += result[j - 1];
        }
        return result;
    }
};

int main()
{
    Solution s;
    Solution2 s2;
    for (int i = 0; i < 10; i++)
    {
        for (auto j : s.getRow(i))
            cout << j << " ";
        cout << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        for (auto j : s2.getRow(i))
            cout << j << " ";
        cout << endl;
    }
}