Short Approach
      Add the newInterval into the list of intervals.
      Sort intervals by start time.
      Traverse through intervals:
      If current interval overlaps with the last interval in result → merge them.
      Otherwise, add as a new interval.
      Return merged list.

🔹 Code with Short Comments
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);                  // Step 1: add new interval
    sort(intervals.begin(), intervals.end());          // Step 2: sort by start

    vector<vector<int>> res;
    res.push_back(intervals[0]);                       // init with first interval

    for (int i = 1; i < intervals.size(); i++) {
        if (res.back()[1] >= intervals[i][0]) {        // overlap → merge
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);               // no overlap → push
        }
    }
    return res;                                        // merged intervals
}
