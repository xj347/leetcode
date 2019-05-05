class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int f = 0, f_1 = 1, f_2 = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] >= '1' && s[i] <= '9')
                f += f_1;
            if (s[i-1] == '1' || (s[i-1] == '2' && (s[i] >= '0' && s[i] <= '6')))
                f += f_2;
            f_2 = f_1;
            f_1 = f;
            f = 0;
        }
        return f_1;
    }
};