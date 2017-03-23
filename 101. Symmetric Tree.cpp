//101. Symmetric Tree
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

//recurse
//time O(n) space O(logn)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;

        return left->val == right->val
            && isSymmetric(left->left, right->right)
            && isSymmetric(left->right, right->left);
    }
};

//iteration
//time O(n) space O(logn)
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);

        while (!s.empty())
        {
            TreeNode* p = s.top(); s.pop();
            TreeNode* q = s.top(); s.pop();

            if (p == nullptr && q == nullptr)
                continue;
            if (p == nullptr || q == nullptr)
                return false;
            if (p->val != q->val)
                return false;

            s.push(p->left);
            s.push(q->right);

            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};