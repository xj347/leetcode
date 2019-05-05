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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd)
    {
        if (pStart > pEnd || iStart > iEnd || pEnd - pStart != iEnd - iStart)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pEnd]);
        int i;
        for (i = iStart; i < iEnd; i++)
        {
            if (inorder[i] == root->val)
            {
                break;
            }
        }
        int rightLen = iEnd - i;
        root->left = build(postorder, inorder, pStart, pEnd-rightLen-1, iStart, i-1);
        root->right = build(postorder, inorder, pEnd-rightLen, pEnd-1, i+1, iEnd);
        return root;
    }
};