//4. Median of Two Sorted Arrays
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//T: log(m + n) S: log(M + n)
class Solution {
typedef vector<int>::const_iterator itr;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;

        if (total & 0x1)
            return find_kth(nums1.cbegin(), m, nums2.cbegin(), n, total / 2 + 1);
        else
            return (find_kth(nums1.cbegin(), m, nums2.cbegin(), n, total / 2) +
                find_kth(nums1.cbegin(), m, nums2.cbegin(), n, total / 2 + 1)) / 2.0;
    }

private:
    static int find_kth(itr a, int m, itr b, int n, int k)
    {
        //always put the shorter one in left
        if (m > n)
            return find_kth(b, n, a, m, k);
        if (m == 0)
            return *(b + k - 1);
        if (k == 1)
            return min(a[0], b[0]);

        int part_a = min(k / 2, m), part_b = k - part_a;

        if (*(a + part_a - 1) < *(b + part_b - 1))
            return find_kth(a + part_a, m - part_a, b, n, k - part_a);
        else if ((*(a + part_a - 1) > *(b + part_b - 1)))
            return find_kth(a, m, b + part_b, n - part_b, k - part_b);
        else
            return *(a + part_a - 1);
    }
};

int main()
{
    Solution s;
    vector<vector<int> > test = {
        {1, 3},
        {2} },
        test2 = {
            {1, 2},
            {3, 4} };
    cout << s.findMedianSortedArrays(test[0], test[1]) << endl
        << s.findMedianSortedArrays(test2[0], test2[1]) << endl;
}