class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxSum = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};