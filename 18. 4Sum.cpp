//18. 4Sum
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

//time and space O(n ^ 2)
//use a multi hash map to cache any two elements' sum that's in the vector
//and traverse the cache, and find the differ.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> > result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        unordered_multimap<int, pair<int, int>> sum_cache;
        //cache sum and tow indexs
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                sum_cache.insert({ nums[i] + nums[j], {i, j} });
        }

        for (auto itr = sum_cache.begin(); itr != sum_cache.end(); itr++)
        {
            int differ = target - itr->first;
            auto range = sum_cache.equal_range(differ);
            for (auto itr2 = range.first; itr2 != range.second; itr2++)
            {
                int a = itr->second.first,
                    b = itr->second.second,
                    c = itr2->second.first,
                    d = itr2->second.second;
                //check if there are same indexs in two distinct groups
                if (a != c && a != d && b != c && b != d)
                {
                    vector<int> v{ nums[a], nums[b], nums[c], nums[d] };
                    sort(v.begin(), v.end());
                    result.push_back(v);
                }
            }
        }
        //rearrange and  remove duplicates
        sort(result.begin(), result.end());
        auto itr = unique(result.begin(), result.end());
        result.erase(itr, result.end());
        return result;
    }
};