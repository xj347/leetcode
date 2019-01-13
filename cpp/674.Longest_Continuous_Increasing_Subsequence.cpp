/*
Date : 2019.1.13
Link : https://leetcode.com/problems/longest-continuous-increasing-subsequence/
Difficulty : Easy
Description : 
    Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
    Example 1:
    Input: [1,3,5,4,7]
    Output: 3
    Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
    Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
*/

int findLengthOfLCIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    int increasing_len = 1, res = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i-1])
        {
            increasing_len++;
        }
        else
        {
            res = max(res, increasing_len);
            increasing_len = 1;
        }
    }
    res = max(res, increasing_len);
    return res;
}

