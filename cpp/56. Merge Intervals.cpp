class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        int i = 1;
        while (i < intervals.size())
        {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};