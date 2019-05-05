class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, n, "", res);
        return res;
    }
    
    void dfs(int leftNum, int rightNum, int n, string path, vector<string> &res)
    {
        if (rightNum > leftNum || leftNum > n)
            return;
        if (leftNum == n && rightNum == n)
        {
            res.push_back(path);
            return;
        }
        dfs(leftNum+1, rightNum, n, path + "(", res);
        dfs(leftNum, rightNum+1, n, path + ")", res);
    }
};