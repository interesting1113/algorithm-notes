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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(p->next) {
            // q从p的next位置开始移动，如果q存在并且q的值等于p的next的值，q就往后移动
            auto q = p->next;
            while(q && q->val == p->next->val) q = q->next;
            // 如果p，q间的长度为1，则将当前值保留下来，p向后移动
            if (q == p->next->next) p = p->next;
            else p->next = q;
        }
        return dummy->next;
    }
};