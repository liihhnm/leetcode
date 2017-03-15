//70. Climbing Stairs
#include <vector>
#include <algorithm>

using namespace std;

//登上n阶台阶可分为： 先登上 n - 1 阶， 再登 1 阶
//                    先登上 n - 2 阶， 再登 2 阶
//f(n) = f(n - 1) + f(n - 2)
//f(0) = 1 f(1) = 1
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;

        int sum = 0;
        int current = 1, previous = 1;
        for (int i = 2; i <= n; ++i)
        {
            sum = current + previous;
            previous = current;
            current = sum;
        }
        return sum;
    }
};