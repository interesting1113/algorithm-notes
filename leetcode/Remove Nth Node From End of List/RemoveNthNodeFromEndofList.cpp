/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        int len = 0;
        for (auto p = dummy; p; p = p->next) {
            len ++;
        }

        auto p = dummy;
        for (int i = 0; i < len - n - 1; i ++) {
            p = p->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};