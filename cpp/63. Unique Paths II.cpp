class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> f(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
                f[i][0] = 1;
            else
                break;
        }
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0)
                f[0][i] = 1;
            else
                break;
        }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    f[i][j] = 0;
                else
                    f[i][j] = f[i][j-1] + f[i-1][j];
            }
        return f[m-1][n-1];
    }
};