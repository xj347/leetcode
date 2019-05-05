class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        int reach = 0;
        for (int i = 0; i <= reach && i < nums.size(); i++)
        {
            reach = max(reach, nums[i] + i);
            if (reach >= nums.size() - 1)
                return true;
        }
        return false;
    }
};