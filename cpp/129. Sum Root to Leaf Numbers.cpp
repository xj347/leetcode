class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    
    void helper(TreeNode* root, int num, int &sum)
    {
        if (!root)
            return;
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            sum += num;
        }
        helper(root->left, num, sum);
        helper(root->right, num, sum);
    }
};