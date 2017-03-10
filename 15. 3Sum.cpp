#include <vector>
#include <iostream>
#include <algorithm> //sort
#include <unordered_map>

using namespace std;

//O(n ^ 2)
//排序 左右夹逼
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        if (nums.size() < 3)
            return result;

        sort(nums.begin(), nums.end());
        int goal = 0;
        auto last = nums.end() - 1;

        for (auto i = nums.begin(); i < last - 1; ++i)
        {
            //skip duplicates
            if (i > nums.begin() && *i == *(i - 1))
                continue;
            //set left and right board index
            auto j = i + 1;
            auto k = last;
            //挟持逼近
            while (j < k)
            {
                if (*i + *j + *k < goal)
                {
                    ++j;
                    while (*j == *(j - 1) && j < k) ++j;
                }
                else if (*i + *j + *k > goal)
                {
                    --k;
                    while (*k == *(k + 1) && j < k) --k;
                }
                else
                {
                    result.push_back({ *i, *j, *k });
                    ++j; --k;
                    while (*j == *(j - 1) && j < k) ++j;
                    while (*k == *(k + 1) && j < k) --k;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    Solution s2;
    vector<int> nums = { -1, 0, 1, 2, -1, -4};
    for (auto& v : s.threeSum(nums))
    {
        for (auto& num : v)
            cout << num << " ";
        cout << endl;
    }

}