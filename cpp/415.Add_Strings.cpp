/*
Date : 2019.1.13
Link : https://leetcode.com/problems/add-strings/
Difficulty : Easy
Description : 
    Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
    Note:
    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

string addStrings(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size();
    int carry= 0, digit1 = 0, digit2 = 0;
    string sum = "";
    for (int i = 1; i <= max(len1, len2); i++)
    {
        digit1 = digit2 = 0;
        if (len1 >= i)
            digit1 = num1[len1 - i] - '0';
        if (len2 >= i)
            digit2 = num2[len2 - i] - '0';
        int cur_sum = digit1 + digit2 + carry;
        sum = std::to_string(cur_sum % 10) + sum;
        carry = cur_sum / 10;
    }
    if (carry)
        sum = "1" + sum;
    return sum;
}
