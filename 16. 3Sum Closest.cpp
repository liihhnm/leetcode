#include <vector>
#include <iostream>
#include <algorithm> //sort
#include <climits>
#include <cmath>

using namespace std;

//排序 挟持逼近
//O(n ^ 2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());

        auto last = nums.end() - 1;
        for (auto i = nums.begin(); i < last - 1; ++i)
        {
            //set two board
            auto j = i + 1;
            auto k = last;
            //holding approximation
            while (j < k)
            {
                int sum = *i + *j + *k;
                int gap = abs(sum - target);
                if (gap < min_gap)
                {
                    result = sum;
                    min_gap = gap;
                }

                if (sum < target) ++j;
                else if (sum > target) --k;
                else return result;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    Solution s2;
    vector<int> nums = { -1, 2, 1, -4 };
    cout << s.threeSumClosest(nums, 1) << endl;


}