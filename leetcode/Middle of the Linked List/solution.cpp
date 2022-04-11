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

// 双指针法
// 维护两个指针p和q, 一开始都指向链表的头结点
// 然后开始遍历链表, p一次走一步, q一次走两步
// 当q走到尾结点时, 返回p; 当q没法走两步时, 返回p的后继结点(右边的中间结点)
// 时间复杂度O(n)
// 空间复杂度O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto p = head, q = head;
        while (p && p->next) {
            q = q->next;
            p = p->next->next;
        }
        return q;
    }
};

// 单指针遍历两遍
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        int cnt = 0;
        while (p) {
            cnt ++;
            p = p->next;
        }
        int k = 0;
        p = head;
        while (k < cnt / 2) {
            k ++;
            p = p->next;
        }
        return p;
    }
};