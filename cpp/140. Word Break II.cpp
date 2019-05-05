class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if (s.empty()) return res;
        int n = s.size();
        unordered_map<int, vector<string>> cache;
        res = findPath(0, s, cache, wordDict);
        return res;
    }
    
    vector<string> findPath(int pos, string &s, unordered_map<int, vector<string>> &cache, vector<string>& wordDict) {
        if (cache.find(pos) != cache.end())
        {
            return cache[pos];
        }
        vector<string> res;
        if (pos == s.size())
        {
            res.push_back("");
            return res;
        }
        for (int i = pos; i < s.size(); i++)
        {
            string sub = s.substr(pos, i-pos+1);
            if (find(wordDict.begin(), wordDict.end(), sub) != wordDict.end())
            {
                vector<string> tails = findPath(i+1, s, cache, wordDict);
                for (string tail : tails)
                    res.push_back(sub + (tail == "" ? "":" ") + tail);
            }
        }
        cache[pos] = res;
        return res;
    }
};