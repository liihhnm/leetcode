//206. Reverse Linked List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//iterate in place version
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode sentry(-1);
        sentry.next = head;
        ListNode* reverse_begin = sentry.next;
        if (reverse_begin == nullptr || reverse_begin->next == nullptr)
            return sentry.next;
        ListNode* current = reverse_begin->next;

        while (current != nullptr)
        {
            reverse_begin->next = current->next;
            current->next = sentry.next;
            sentry.next = current;

            current = reverse_begin->next;
        }
        return sentry.next;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode sentry(-1);
        reverse_list_helper(head, &sentry);
        return sentry.next;
    }
private:
    void reverse_list_helper(ListNode* root, ListNode* sentry)
    {
        if (root == nullptr)
            return;
        ListNode* new_node = new ListNode(root->val);
        new_node->next = sentry->next;
        sentry->next = new_node;
        reverse_list_helper(root->next, sentry);
    }
};