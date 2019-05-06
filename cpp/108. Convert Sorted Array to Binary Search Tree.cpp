class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* buildBST(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid-1);
        root->right = buildBST(nums, mid+1, right);
        return root;
    }
};