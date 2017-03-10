//144. Binary Tree Preorder Traversal
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
        stack<TreeNode *> s;
        
        if (root == nullptr)
            return result;
        s.push(root);

        while (!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();

            result.push_back(temp->val);
            
            if (temp->right != nullptr)
                s.push(temp->right);
            if (temp->left != nullptr)
                s.push(temp->left);
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
        
        if (root == nullptr)
            return result;

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

                //current 尚未线索化
                if (temp->right == nullptr)
                {
                    result.push_back(current->val);
                    temp->right = current;
                    prev = current;
                    current = current->left;
                }
                //已经线索化, 删除线索
                else
                {
                    temp->right = nullptr;
                    current = current->right;
                }
            }
        }
        return result;
    }
};
