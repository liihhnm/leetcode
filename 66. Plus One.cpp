//66. Plus One
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int size = digits.size();
        if (size == 0)
            return result;

        int carry = 1;
        for (int i = size - 1; i >= 0; --i)
        {
            int sum = digits[i] + carry;
            result.insert(result.begin(), sum % 10);
            carry = sum / 10;
        }
        if (carry > 0)
            result.insert(result.begin(), 1);
        return result;
    }
};