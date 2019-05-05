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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode *root, vector<int> &res)
    {
        if (root)
        {
            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    }

    //iterative
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode *cur = root, *pre = NULL;
        while (cur != NULL || !nodeStack.empty())
        {
            if (cur)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *tmp = nodeStack.top();
                if (tmp->right != NULL && pre != tmp->right)
                {
                    cur = tmp->right;
                }
                else
                {
                    res.push_back(tmp->val);
                    nodeStack.pop();
                    pre = tmp;
                }
            }
        }
        return res;
    }
};