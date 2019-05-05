class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int reach = 0, lastReach = 0, step = 0;
        for (int i = 0; i <= reach && i < nums.size(); i++)
        {
            if (i > lastReach)
            {
                step++;
                lastReach = reach;
                if (reach >= nums.size() - 1)
                    return step;
            }
            reach = max(reach, nums[i] + i);
        }
        return 0;
    }
};