//131. Palindrome Partitioning
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

//dfs
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int size = s.size();
        if (size == 0)
            return result;

        vector<string> sub_strings;
        dfs(s, result, sub_strings, 0);
        return result;
    }

private:
    void dfs(const string& s, vector<vector<string>>& result, vector<string>& sub_strings, int start)
    {
        int size = s.size();
        if (start == size)
        {
            result.push_back(sub_strings);
            return;
        }

        for (int i = start; i < size; ++i)
        {
            if (is_palindrome(s, start, i))
            {
                sub_strings.push_back(s.substr(start, i - start + 1));
                dfs(s, result, sub_strings, i + 1);
                sub_strings.pop_back();
            }
        }
    }

    bool is_palindrome(const string& s, int start, int end)
    {
        while (start < end && s[start] == s[end])
        {
            start++;
            end--;
        }
        return start >= end;
    }
};

int main()
{
    vector<string> test = { "aab", "abcdcb" };
    Solution slt;
    for (const auto& s : test)
    {
        for (auto& arr : slt.partition(s))
        {
            copy(arr.begin(), arr.end(), ostream_iterator<string>(cout, " "));
            cout << endl;
        }
        cout << endl;
    }
}