//103. Binary Tree Zigzag Level Order Traversal
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

//time O(n) space O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> current, next;
        bool zigzag = true;
        current.push(root);

        while (!current.empty())
        {
            vector<int> level;
            while (!current.empty())
            {
                TreeNode* node_ptr = current.front();
                current.pop();
                level.push_back(node_ptr->val);
                if (node_ptr->left != nullptr)
                    next.push(node_ptr->left);
                if (node_ptr->right != nullptr)
                    next.push(node_ptr->right);
            }
            if (!zigzag)
                reverse(level.begin(), level.end());
            result.push_back(level);
            swap(current, next);
            zigzag = !zigzag;
        }
        return result;
    }
};