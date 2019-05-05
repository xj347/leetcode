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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        return merge(lists, 0, lists.size()-1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        int mid = (left + right) / 2;
        ListNode *list1 = merge(lists, left, mid);
        ListNode *list2 = merge(lists, mid+1, right);
        return mergeTwoLists(list1, list2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next =l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        return dummy.next;
    }
};