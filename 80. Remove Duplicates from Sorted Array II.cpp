//80. Remove Duplicates from Sorted Array II
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int index = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }
};

int main()
{
    Solution s;
    Solution s2;
    vector<vector<int> > test = {
        {1, 1, 1, 2, 3, 4},
        {1, 1, 1,1 ,1 },
        {},
        {5, 4, 3, 1, 1} };
    for (auto& arr : test)
    {
        cout << s2.removeDuplicates(arr) << endl;
        for (const auto& num : arr)
            cout << num << " ";
        cout << endl << endl;
    }
        
}