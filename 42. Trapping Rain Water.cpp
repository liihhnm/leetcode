//42. Trapping Rain Water

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size <= 2)
            return 0;
        //找到每个位置上左右最高的墙壁
        vector<int> left_wall(size, 0);
        vector<int> right_wall(size, 0);
        for (int i = 1; i < size; ++i)
        {
            left_wall[i] = max(left_wall[i - 1], height[i - 1]);
            right_wall[size - 1 - i] = max(right_wall[size - i], height[size - i]);
        }        
        //找到两边的较低者, 并与自身比较，得到所能容纳水的高度
        int sum = 0;
        for (int i = 0; i < size; ++i)
        {
            int wall_height = min(left_wall[i], right_wall[i]);
            if (height[i] < wall_height)
                sum += wall_height - height[i];
        }
        return sum;

    }
};