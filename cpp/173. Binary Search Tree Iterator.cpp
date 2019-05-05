/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> NodeStack;
public:
    BSTIterator(TreeNode* root) {
        while (root)
        {
            NodeStack.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = NodeStack.top();
        int res = node->val;
        NodeStack.pop();
        TreeNode *cur = node->right;
        while (cur)
        {
            NodeStack.push(cur);
            cur = cur->left;
        }    
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !NodeStack.empty();
    }
};