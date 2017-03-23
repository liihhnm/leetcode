//Binary Tree Level Order Traversal II
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> current, next;
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
            result.push_back(level);
            swap(current, next);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};