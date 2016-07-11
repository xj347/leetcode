/*
Author : xia jie
Date : 2016.7.11
Source : https://leetcode.com/problems/powx-n/
Difficulty : Medium
Description : Implement pow(x, n).
*/
class Solution {

public:

    double myPow(double x, int n)
    {
      if(n < 0)
        return 1.0 / pow(x, -n);
      else
        return pow(x,n);
    }

    double pow(double x, int n)
    {
      if(n == 0)
        return 1;
      double half = pow(x, n/2);
      if(n % 2 == 0)
        return half * half;
      else
        return half * half * x;
    }
};
