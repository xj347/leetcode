class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> path;
        dfs(0, path, s, res);
        return res;
    }
    
    void dfs(int index, vector<string> &path, string &s, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i-index+1));
                dfs(i+1, path, s, res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int left, int right)
    {
        while(left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};