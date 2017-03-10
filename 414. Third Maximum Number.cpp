//414. Third Maximum Number
//array
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>// use min, max
#include <climits> // use INT_MIN

using namespace std;

//16ms
class Solution { 
public:
    int thirdMax(vector<int>& nums)
    {
        set<int> big3;
        for (int number : nums)
        {
            big3.insert(number);
            if (big3.size() > 3)
                big3.erase(big3.begin());
         }

        if (big3.size() == 3)
            return *big3.begin();
        else
            return *big3.rbegin();
    }
};

//6ms Because only use primitive array operation, so faster
class Solution2 {
public:
    int thirdMax(vector<int>& nums)
    {
        int big3[3] = { INT_MIN, INT_MIN, INT_MIN };
        int array_size = 0; // just valid element
        bool meet_INT_MIN = false;
        bool repeat = false;

        for (int number : nums)
        {
            //judge if number equal to INT_MIN and if repeat
            if (number == INT_MIN)
            {
                if (!meet_INT_MIN && array_size < 3)
                {
                    array_size++;
                    meet_INT_MIN = true;
                }
                continue;
            }
            //judge repeat
            for (int i = 0; i != 3; i++)
            {
                if (number == big3[i])
                {
                    repeat = true;
                    break;
                }
            }
            if (repeat)
            {
                repeat = false;
                continue;
            }
            //add or replace element of big3
            if (array_size < 3)
            {
                big3[array_size] = number;
                array_size++;
            }
            else
            {
                int min = big3[0], min_index = 0;
                for (int i = 1; i != 3; i++)
                {
                    if (big3[i] < min)
                    {
                        min = big3[i];
                        min_index = i;
                    }
                }
                if (number > min)
                    big3[min_index] = number;
            }
        }
        return array_size < 3 ?
            *max_element(begin(big3), end(big3)) :
            *min_element(begin(big3), end(big3));
    }
};

int main()
{
    Solution s;
    Solution2 s2;
    vector<vector<int>> test = {
        { 1, 2, 3 },
    { 1, 4 },
    { 1, 1, 1, 2 },
    {1, 2, INT_MIN},
    {INT_MIN, INT_MIN, INT_MIN, INT_MIN, 1, 1, 1},
    {1, 2, 4, INT_MIN}
    };

    for (auto i = test.begin(); i != test.end(); i++)
        cout << s.thirdMax(*i) << endl;
    cout << endl;
    for (auto i = test.begin(); i != test.end(); i++)
        cout << s2.thirdMax(*i) << endl;
}