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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int s, int e)
    {
        vector<TreeNode*> res;
        if (s > e)
        {
            res.push_back(NULL);
            return res;
        }
        for (int r = s; r <= e; r++)
        {
            vector<TreeNode*> leftRes = generate(s, r-1);
            vector<TreeNode*> rightRes = generate(r+1, e);
            for (int i = 0; i < leftRes.size(); i++)
                for (int j = 0; j < rightRes.size(); j++)
                {
                    TreeNode *root = new TreeNode(r);
                    root->left = leftRes[i];
                    root->right = rightRes[j];
                    res.push_back(root);
                }
        }
        return res;
    }
};