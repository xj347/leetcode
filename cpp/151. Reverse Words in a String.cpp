class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, idx = 0, start, end;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
                i++;
            start = i;
            while(i < s.size() && s[i] != ' ')
                i++;
            end = i;
            if (start >= end)
                break;
            reverse(s.begin() + start, s.begin() + end);
            if (idx > 0)
                s[idx++] = ' ';
            for (int j = start; j < end && j < s.size(); j++)
                s[idx++] = s[j];
        }
        s.resize(idx);
        return s;
    }
};