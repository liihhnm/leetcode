//99. Recover Binary Search Tree
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

//use morris inorder traversal
//record the out-of-order pair of pointers
//time O(n) space O(1)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (root == nullptr)
            return;
        pair<TreeNode*, TreeNode*> out_of_order(nullptr, nullptr);
        //record of the pair
        TreeNode* prev = nullptr, * current = root;

        while (current != nullptr)
        {
            if (current->left == nullptr)
            {
                check_broken(out_of_order, prev, current);
                prev = current;
                current = current->right;
            }
            else
            {
                TreeNode* temp = current->left;
                while (temp->right != current && temp->right != nullptr)
                    temp = temp->right;

                if (temp->right == nullptr)
                {
                    temp->right = current;
                    current = current->left;
                }
                else
                {
                    check_broken(out_of_order, prev, current);
                    temp->right = nullptr;
                    prev = current;
                    current = current->right;
                }
            }
        }
        swap(out_of_order.first->val, out_of_order.second->val);
    }

private:
    void check_broken(pair<TreeNode*, TreeNode*>& out_of_order, 
        TreeNode* prev, 
        TreeNode* current)
    {
        if (prev != nullptr && prev->val > current->val)
        {
            //当遇到第一个打破顺序的大元素时 out_of_order.first 仍旧为刚定义是的初始值 nullptr
            //故此时将其指针存入
            if (out_of_order.first == nullptr)
                out_of_order.first = prev;
            out_of_order.second = current;
        }
    }
};

int main()
{
    TreeNode * second = new TreeNode(1);
    TreeNode * first = new TreeNode(0);
    first->left = second;
    Solution s;
    s.recoverTree(first);
    cout << "done";
    delete second;
    delete first;
}