//2. Add Two Numbers
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sentry(-1);
        ListNode* previous = &sentry;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int left = (l1 == nullptr) ? 0 : l1->val;
            int right = (l2 == nullptr) ? 0 : l2->val;
            int value = (left + right + carry) % 10;
            carry = (left + right + carry) / 10;

            previous->next = new ListNode(value);
            previous = previous->next;

            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
        }
        if (carry > 0)
            previous->next = new ListNode(carry);
        return sentry.next;
    }
};