#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//T: 0(n) s: O(n) 9ms
//use hash table
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> visited;

        for (auto& i : nums)
            visited[i] = false;

        int longest = 0;
        
        //一次循环找到一个簇
        for (auto& i : nums)
        {
            if (!visited[i])
            {
                visited[i] = true;
                int length = 1;
                for (int j = i + 1; visited.find(j) != visited.end(); ++j)
                {
                    visited[j] = true;
                    length++;
                }
                for (int j = i - 1; visited.find(j) != visited.end(); --j)
                {
                    visited[j] = true;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

//T: O(n) S: O(n) 12ms
//use union set
//将连续的数构成的簇的长度信息 保存在当前簇中最大最小值map的value中
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int, int> cluster;

        int size = nums.size();
        int longest = 1;
        for (int i = 0; i < size; ++i)
        {
            if (cluster.find(nums[i]) != cluster.end())
                continue;

            cluster[nums[i]] = 1;
            if (cluster.find(nums[i] + 1) != cluster.end())
                longest = max(longest, union_two(cluster, nums[i], nums[i] + 1));
            if (cluster.find(nums[i] - 1) != cluster.end())
                longest = max(longest, union_two(cluster, nums[i] - 1, nums[i]));
        }
        return size == 0 ? 0 : longest;
    }

private:
    int union_two(unordered_map<int, int>& m, int left, int right)
    {
        int upper = right + m[right] - 1;
        int lower = left - m[left] + 1;
        int length = upper - lower + 1;

        m[upper] = length;
        m[lower] = length;
        return length;
    }
};

int main()
{
    Solution2 s;
    vector<int> test = { 100, 4, 200, 3, 1, 2 };
    cout << s.longestConsecutive(test) << endl;
}