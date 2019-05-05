class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty() || target <= 0)
            return res;
        vector<int> path;
        dfs(0, target, path, res, candidates);
        return res;
    }
    
    void dfs(int index, int gap, vector<int> &path, vector<vector<int>> &res, vector<int>& candidates)
    {
        if (gap < 0)
            return;
        if (gap == 0)
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(i, gap - candidates[i], path, res, candidates);
            path.pop_back();
        }
    }
};