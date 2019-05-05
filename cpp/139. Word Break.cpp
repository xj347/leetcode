class Solution {
public:
    //f[i]=f[j] && str(j+1,i) in dict
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        int n = s.size();
        vector<bool> f(n+1, false);
        f[0] = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
            {
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end())
                {
                    f[i+1] = true;
                    break;
                }
            }
        return f[n];
    }
};