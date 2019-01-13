/*
Date : 2019.1.13
Link : https://leetcode.com/problems/reverse-only-letters/
Difficulty : Easy
Description : 
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
    Example 1:
    Input: "ab-cd"
    Output: "dc-ba"
    Example 2:
    Input: "a-bC-dEf-ghIj"
    Output: "j-Ih-gfE-dCba"
    Note:
        S.length <= 100
        33 <= S[i].ASCIIcode <= 122 
        S doesn't contain \ or "
*/

string reverseOnlyLetters(string S) {
    string res = S;
    int i = S.size()-1, j = 0;
    while (j < S.size())
    {
        if (!isalpha(S[j]))
        {
            j++;
            continue;
        }
        else
        {
            while (!isalpha(S[i]))
                i--;
            res[j] = S[i];
            i--;
            j++;
        }
    }
    return res;
}
