/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr; // 定义一个空指针
        auto cur = head; // 把头节点存到当前节点
        while (cur) {
            auto next = cur->next; //因为下面的操作会改变当前节点的下一个节点，所以需要先存下
            cur->next = pre; //让当前节点的下一个指针往回指
            pre = cur; //pre存下当前节点，让后面的节点指向pre
            cur = next; // 移动当前节点
        }
        return pre;
    }
};