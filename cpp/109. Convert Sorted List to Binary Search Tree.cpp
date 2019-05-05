class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode *p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        return buildBST(head, 0, len - 1);
    }
    
    TreeNode* buildBST(ListNode* &head, int left, int right)
    {
        if (!head)
            return NULL;
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *leftRoot = buildBST(head, left, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = leftRoot;
        root->right = buildBST(head, mid + 1, right);
        return root;
    }
};