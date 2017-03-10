//81. Search in Rotated Sorted Array II
//can have duplicates
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin = 0, last = nums.size() - 1;

        while (begin <= last)
        {
            int mid = begin + (last - begin) / 2;
            if (target == nums[mid])
                return true;

            if (nums[begin] < nums[mid])
            {
                if (target >= nums[begin] && target < nums[mid])
                    last = mid - 1;
                else
                    begin = mid + 1;
            }
            else if (nums[begin] > nums[mid])
            {
                if (target > nums[mid] && target <= nums[last])
                    begin = mid + 1;
                else
                    last = mid - 1;
            }
            else
                begin++;
        }

        return false;
    }
};

int main()
{
    Solution s;
    cout << s.search(vector<int>({ 1, 3, 1, 1, 1 }), 2) << endl;
}