//86. Partition List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_list_sentry(-1);
        ListNode right_list_sentry(-1);

        ListNode* left_previous = &left_list_sentry;
        ListNode* right_previous = &right_list_sentry;

        for (ListNode* current = head; current != nullptr; current = current->next)
        {
            if (current->val < x)
            {
                left_previous->next = current;
                left_previous = left_previous->next;
            }
            else
            {
                right_previous->next = current;
                right_previous = current;
            }
        }
        left_previous->next = right_list_sentry.next;
        right_previous->next = nullptr;

        return left_list_sentry.next;
    }
};