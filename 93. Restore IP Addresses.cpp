//93. Restore IP Addresses
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//dfs
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> sub_strings;
        dfs(s, result, sub_strings, 0);
        return result;
    }

private:
    void dfs(const string& s, vector<string>& result, vector<string>& sub_strings, int start)
    {
        if (sub_strings.size() == 4 && start == s.size())
        {
            result.push_back(sub_strings[0] + '.' + sub_strings[1] + '.' + sub_strings[2] + '.' + sub_strings[3]);
            return;
        }
        //prune
        if (s.size() - start < 4 - sub_strings.size())
            return;
        if (s.size() - start > (4 - sub_strings.size()) * 3)
            return;

        //find a aviliable number, and dfs the rest string
        int num = 0;
        for (int i = start; i < start + 3; ++i)
        {
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                break;

            sub_strings.push_back(s.substr(start, i - start + 1));
            dfs(s, result, sub_strings, i + 1);
            sub_strings.pop_back();

            //avoid prefix zero, but allow single zero
            if (num == 0)
                break;
        }
    }
};

int main()
{
    string test = "25525511135";
    Solution s;
    for (auto& str : s.restoreIpAddresses(test))
        cout << str << endl;
    return 0;
}