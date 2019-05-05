class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
    
    int helper(TreeNode* root, int &maxSum)
    {
        if (!root)
            return 0;
        int leftMax = helper(root->left, maxSum);
        int rightMax = helper(root->right, maxSum);
        int pathSum = root->val;
        if (leftMax > 0)
            pathSum += leftMax;
        if (rightMax > 0)
            pathSum += rightMax;
        if (pathSum > maxSum)
            maxSum = pathSum;
        return max(leftMax, rightMax) > 0 ? root->val + max(leftMax, rightMax) : root->val;
    }
};