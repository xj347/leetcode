class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        for (; i < intervals.size() && intervals[i][1] < newInterval[0]; i++)
        {
            res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        if (i < intervals.size())
            res.back()[0] = min(res.back()[0], intervals[i][0]);
        for (; i < intervals.size() && intervals[i][0] <= newInterval[1]; i++)
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        for (; i < intervals.size(); i++)
        {
            res.push_back(intervals[i]);          
        }
        return res;
    }
};