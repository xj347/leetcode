/*
Date : 2016.7.11
Source : https://leetcode.com/problems/powx-n/
Difficulty : Medium
Description : Implement pow(x, n).
*/

#include <iostream>
#include <cmath>
using namespace std;

// Recursive
double myPow(double x, int n)
{
  if(n < 0)
    return 1.0 / pow(x, -n);
  else
    return pow(x,n);

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

// Iterative
double myPow(double x, int n)
{
  unsigned int N = abs(n);  // take care of overflow
  double res = 1.0;
  while(N > 0)
  {
    if(N & 1)
      res = res * x;
    N = N >> 1;
    x = x * x;
  }
  return n < 0 ? 1 / res : res;
}

int main()
{
  myPow(2,-2147483648);
  return 0;
}
