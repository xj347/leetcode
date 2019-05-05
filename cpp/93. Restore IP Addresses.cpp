class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(0, 0, "", s, res);
        return res;
    }
    
    void dfs(int index, int step, string path, string &s, vector<string> &res)
    {
        if (s.size() - index < 4 - step || s.size() - index > 3 * (4 - step))
            return;
        if (step == 4)
        {
            res.push_back(path);
            return;
        }
        for (int j = 1; j <= 3 && index + j <= s.size(); j++)
        {
            string curNum = s.substr(index, j);
            if (curNum.size() == 3 && curNum > "255")
                continue;
            if (curNum.size() >= 2 && curNum[0] == '0')
                continue;
            if (index != 0)
                dfs(index+j, step+1, path + '.' + curNum, s, res);
            else
                dfs(index+j, step+1, curNum, s, res);
        }
    }
};