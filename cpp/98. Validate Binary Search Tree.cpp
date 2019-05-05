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
    //BST定义
    bool isValidBST(TreeNode* root) {
        return validBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
    
    bool validBST(TreeNode* root, long long lower_bound, long long upper_bound)
    {
        if (!root)
            return true;
        return root->val > lower_bound && root->val < upper_bound &&
               validBST(root->left, lower_bound, root->val) &&
               validBST(root->right, root->val, upper_bound);
    }
    
    //BST性质
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
    
    bool inorder(TreeNode* root, TreeNode* &prev)
    {
        if (!root) return true;
        bool left = inorder(root->left, prev);
        if (!left)
            return false;
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        return inorder(root->right, prev);
    }
};