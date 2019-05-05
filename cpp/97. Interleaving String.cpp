class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3)
            return false;
        vector<vector<bool>> f(len1+1,vector<bool>(len2+1,false));
        f[0][0] = true;
        for (int i = 1; i <= len1; i++)
        {
            if (f[i-1][0] && s1[i-1] == s3[i-1])
                f[i][0] = true;
        }
        for (int i = 1; i <= len2; i++)
        {
            if (f[0][i-1] && s2[i-1] == s3[i-1])
                f[0][i] = true;
        }
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
            {
                if ((f[i-1][j] && s1[i-1] == s3[i+j-1]) || (f[i][j-1] && s2[j-1] == s3[i+j-1]))
                    f[i][j] = true;
            }
        return f[len1][len2];
    }
};