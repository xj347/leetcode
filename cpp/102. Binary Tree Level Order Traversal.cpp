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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> level;
        queue<TreeNode*> nodeQue;
        nodeQue.push(root);
        while(!nodeQue.empty())
        {
            int n = nodeQue.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = nodeQue.front();
                level.push_back(cur->val);
                if (cur->left)
                    nodeQue.push(cur->left);
                if (cur->right)
                    nodeQue.push(cur->right);
                nodeQue.pop();
            }
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};