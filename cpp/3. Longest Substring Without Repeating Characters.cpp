class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector lastAppear(256, -1);
        int start = -1, maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            start = max(lastAppear[s[i]], start);
            maxLen = max(maxLen, i - start);
            lastAppear[s[i]] = i;
        }
        return maxLen;
    }
};