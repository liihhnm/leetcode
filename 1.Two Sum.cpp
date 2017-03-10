//1.Two Sum
#include <vector>
#include <iostream>
#include <algorithm> //sort
#include <unordered_map>

using namespace std;

//O(nlog(n)) 9ms
//排序 左右夹逼
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result, backup(nums);
        sort(nums.begin(), nums.end());
        
        int lhs = 0, rhs = nums.size() - 1;
        while (rhs > lhs)
        {
            if (nums[lhs] + nums[rhs] > target)
                rhs--;
            else if (nums[lhs] + nums[rhs] < target)
                lhs++;
            else
            {
                int index0, index1;
                for (auto i = backup.cbegin(); i != backup.cend(); i++)
                    if (*i == nums[lhs])
                    {
                        index0 = i - backup.cbegin();
                        break;
                    }
                for (auto i = backup.crbegin(); i != backup.crend(); i++)
                    if (*i == nums[rhs])
                    {
                        index1 = backup.crend() - 1 - i;
                        break;
                    }
                result.push_back(min(index0, index1));
                result.push_back(max(index0, index1));
                return result;
            }
        }
        return result;
    }
};

//average case: O(n)
//worst case: O(n^2)
//up to unordered_map.find()
//13ms
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> nums2index;
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            auto itr = nums2index.find(target - *i);
            if (itr == nums2index.end())
                nums2index[*i] = i - nums.begin();
            else
            {
                result.push_back(itr->second);
                result.push_back(i - nums.begin());
                return result;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    Solution s2;
    vector<int> nums({ 2, 7, 11, 15 });
    int target = 9;
    for (auto i : s.twoSum(nums, target))
        cout << i << " ";
    cout << endl;
    for (auto i : s2.twoSum(nums, target))
        cout << i << " ";
}