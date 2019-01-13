/*
Date : 2016.7.12
Link : https://leetcode.com/problems/sqrtx/
Difficulty : Medium
Description : Implement int sqrt(int x). Compute and return the square root of x.
*/

#include <iostream>
#include <cmath>
using namespace std;

int mySqrt(int x) {
  if(x < 0) return -1;
  if(x == 0 || x == 1) return x;
  int left = 1, right = x/2, mid;
  while(left < right)
  {
    mid = (left + right) / 2 + 1;
    cout<<mid;
    if(x / mid < mid)
      right = mid - 1;
    else if(x / mid > mid)
      left = mid;
    else
      return mid;
  }
  return left;
}

int main()
{
  cout<<mySqrt(6);
  return 0;
}
