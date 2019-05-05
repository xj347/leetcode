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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        while (head)
        {
            ListNode *p = &dummy;
            while (p->next && p->next->val <= head->val)
            {
                p = p->next;
            }
            ListNode *tmp = head->next;
            head->next = p->next;
            p->next = head;
            head = tmp;
        }
        return dummy.next;
    }
};