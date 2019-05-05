

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for (int i = 0; i < nums.size(); i++)
            used[nums[i]] = false;
        int longest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[nums[i]])
                continue;
            used[nums[i]] = true;
            int len = 1;
            for (int l = nums[i] - 1; used.find(l) != used.end(); l--)
            {
                used[l] = true;
                len++;
            }
            for (int r = nums[i] + 1; used.find(r) != used.end(); r++)
            {
                used[r] = true;
                len++;
            }
            longest = max(longest, len);
        }
        return longest;
    }
};