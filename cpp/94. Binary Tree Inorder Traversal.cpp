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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root)
        {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    
    //iterative
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode *cur = root;
        while (cur != NULL || !nodeStack.empty())
        {
            if (cur)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = nodeStack.top();
                res.push_back(cur->val);
                nodeStack.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};