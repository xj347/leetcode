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
    //recursive
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    void preorder(TreeNode* root, vector<int> &res)
    {
        if (root)
        {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }

    //iterative
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        if (root)
            nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode *cur = nodeStack.top();
            res.push_back(cur->val);
            nodeStack.pop();
            if (cur->right)
                nodeStack.push(cur->right);
            if (cur->left)
                nodeStack.push(cur->left);
        }
        return res;
    }
};