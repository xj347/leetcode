class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> columns(n, 0);
        dfs(0, n, columns, res);
        return res;
    }
    
    void dfs(int colIndex, int n, vector<int> &columns, vector<vector<string>> &res)
    {
        if (colIndex == n)
        {
            vector<string> solution;
            for (int i = 0; i < n; i++)
            {
                string row(n, '.');
                for (int j = 0; j < n; j++)
                {
                    if (columns[j] == i)
                        row[j] = 'Q';
                }
                solution.push_back(row);
            }
            res.push_back(solution);
            return;
        }
        
        for (int i = 0; i < n; i++)
        {
            bool valid = true;
            for (int j = 0; j < colIndex; j++)
            {
                if (columns[j] == i || abs(i - columns[j]) == colIndex - j)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                columns[colIndex] = i;
                dfs(colIndex + 1, n, columns, res);
            }
        }
    }
};