// 链表中倒数第k个节点
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
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int n= 0;
        for (auto p = pListHead; p; p = p->next) n ++; // 遍历整个列表看有多少个数
        if (k > n) return NULL;
        auto p = pListHead;
        for (int i = 0; i < n - k; i ++) p = p->next;
        return p;
    }
}