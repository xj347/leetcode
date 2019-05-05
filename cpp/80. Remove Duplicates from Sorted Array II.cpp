class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int index = 1;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] != nums[index-1])
            {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};