/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flat(root);
    }
    
    TreeNode *flat(TreeNode* root)
    {
        if (!root) return NULL;
        TreeNode *L = root->left;
        TreeNode *R = root->right;
        root->left = NULL;
        TreeNode *tail = root;
        if (L)
        {
            tail->right = L;
            tail = flat(L);
        }
        if (R)
        {
            tail->right = R;
            tail = flat(R);
        }
        return tail;
    }
};