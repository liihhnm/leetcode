//100. Same Tree
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

//recurse version
//time O(n) space O(logn)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        return p->val == q->val
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};

//iteration version
//time O(n) space O(logn)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);

        while (!s.empty())
        {
            p = s.top(); s.pop();
            q = s.top(); s.pop();

            if (p == nullptr && q == nullptr)
                continue;
            if (p == nullptr || q == nullptr)
                return false;
            if (p->val != q->val)
                return false;

            s.push(p->left);
            s.push(q->left);

            s.push(p->right);
            s.push(q->right);
        }
    }
};