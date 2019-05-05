class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        int index = -1;
        for (i = n-2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
                break;
        }
        index = i;
        if (index >= 0)
        {
            for (int j = n-1; j > index; j--)
            {
                if (nums[j] > nums[index])
                {
                    swap(nums[j], nums[index]);
                    break;
                }
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};