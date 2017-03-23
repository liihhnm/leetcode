//92. Reverse Linked List II
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode sentry(-1);
        sentry.next = head;
        ListNode* head2 = &sentry;

        for (int i = 0; i < m - 1; ++i)
            head2 = head2->next;
        ListNode* reverse_begin = head2->next;
        ListNode* current = reverse_begin->next;

        for (int i = m; i < n; ++i)
        {
            reverse_begin->next = current->next;
            current->next = head2->next;
            head2->next = current;

            current = reverse_begin->next;
        }
        return sentry.next;
    }
};