//94. Binary Tree Inorder Traversal
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//stack version.
//time O(n) space O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root == nullptr)
            return result;

        TreeNode* temp = root; //左子树递归压栈终止标记指针
        while (!s.empty() || temp != nullptr)
        {
            if (temp != nullptr)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = s.top();
                s.pop();
                result.push_back(temp->val);
                temp = temp->right;
            }
        }
        return result;
    }
};

//morris traversal
//令每个（子）树的根的左节点的最右子节点的右指针指向它
//time O(n) space O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        TreeNode* current = root, *prev = nullptr;

        while (current != nullptr)
        {
            if (current->left == nullptr)
            {
                result.push_back(current->val);
                prev = current;
                current = current->right;
            }
            else
            {
                TreeNode* temp = current->left;
                while (temp->right != nullptr && temp->right != current)
                    temp = temp->right;

                if (temp->right == nullptr)
                {
                    temp->right = current;
                    current = current->left;
                }
                else
                {
                    result.push_back(current->val);
                    temp->right = nullptr;
                    prev = current;
                    current = current->right;
                }
            }
        }
        return result;
    }
};