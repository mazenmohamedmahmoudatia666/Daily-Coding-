class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // Step 1: Add all intervals that end before the new interval starts.
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // Step 2: Merge all overlapping intervals with the new interval.
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        // Add the merged interval (newInterval) to the result.
        result.push_back(newInterval);
        
        // Step 3: Add all intervals that start after the new interval ends.
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};
