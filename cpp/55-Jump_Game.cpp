/*
Author : xia jie
Date : 2016.7.15
Source : https://leetcode.com/problems/jump-game/
Difficulty : Medium
Description :  Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false. 
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool canJump(vector<int>& nums) 
{
  if(nums.empty()) return false;
  int n = nums.size();
  int reach = 0;
  for(int i = 0; i <= reach && i < n; i++)
  {
    reach = max(i + nums[i],reach);
    if(reach >= n-1) return true;
  }
  return false;
}

int main()
{
  vector<int> v1 = vector<int>({2,3,1,1,4});
  vector<int> v2 = vector<int>({3,2,1,0,4});
  cout<<canJump(v1)<<canJump(v2);
  return 0;
}
