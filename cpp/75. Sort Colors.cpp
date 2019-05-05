class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size()-1;
        int i = 0;
        while (i <= blue)
        {
            if (nums[i] == 0)
            {
                swap(nums[red++], nums[i]);
                i++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[blue--], nums[i]);
            }
            else
                i++;
        }
    }
};