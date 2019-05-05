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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd)
    {
        if (pStart > pEnd || iStart > iEnd || pEnd - pStart != iEnd - iStart)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pStart]);
        int i;
        for (i = iStart; i < iEnd; i++)
        {
            if (inorder[i] == root->val)
            {
                break;
            }
        }
        int leftLen = i - iStart;
        root->left = build(preorder, inorder, pStart+1, pStart+leftLen, iStart, i-1);
        root->right = build(preorder, inorder, pStart+leftLen+1, pEnd, i+1, iEnd);
        return root;
    }
};