class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        getPath(root, sum, path, res);
        return res;
    }
    
    void getPath(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == sum)
            {
                res.push_back(path);
            }
        }
        getPath(root->left, sum - root->val, path, res);
        getPath(root->right, sum - root->val, path, res);
        path.pop_back();
    }
};