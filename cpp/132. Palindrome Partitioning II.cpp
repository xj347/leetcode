class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> f(n);
        vector<vector<bool>> palind(n,vector<bool>(n,false));
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
            for (int j = 0; j <= i; j++)
            {
                if (s[i] == s[j] && (i - j <= 2 || palind[j+1][i-1]))
                {
                    f[i] = j == 0 ? 0 : min(f[i], f[j-1] + 1);
                    palind[j][i] = true;
                }
            }
        }
        return f[n-1];
    }
};