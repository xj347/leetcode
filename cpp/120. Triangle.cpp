class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++)
            f[i] = triangle[n-1][i];
        for (int row = n-2; row >= 0; row--)
            for (int i = 0; i <= row; i++)
            {
                f[i] = min(f[i], f[i+1]) + triangle[row][i];
            }
        return f[0];
    }
};