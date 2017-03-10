//31. Next Permutation
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

//O(n)
//1.from right to left, find  the first digit violate the increase order, called partition number.
//2.from right to left, find the first digit which is lager than partition number, called change number.
//3.swap partition number and change number.
//4.reverse all digits on right of the partition index.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        using namespace std::placeholders;
        const auto rfirst = reverse_iterator<vector<int>::iterator>(nums.end());
        const auto rlast = reverse_iterator<vector<int>::iterator>(nums.begin());

        //find parition number
        auto pivot = rfirst + 1;
        while (pivot != rlast && *pivot >= *(pivot - 1))
            pivot++;
        //check if partition number exist
        if (pivot == rlast)
        {
            reverse(rfirst, rlast);
            return;
        }
        //find change number
        auto change = find_if(rfirst, pivot, bind(less<int>(), *pivot, _1));
        //swap two
        swap(*pivot, *change);
        reverse(rfirst, pivot);
        return;
    }
};

int main()
{
    Solution s;
    vector<int> i({ 6, 8, 7, 4, 3, 2 });
    s.nextPermutation(i);
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, ""));

}