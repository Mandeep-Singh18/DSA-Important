Short Approach
      Sort all intervals by end time.
      Use greedy selection: always pick the interval that ends earliest.
      Keep track of lastendtime.
      If current interval starts after or at lastendtime, select it and update lastendtime.
      Count how many non-overlapping intervals are selected.
      Answer = total intervals - selected count (intervals to remove).


🔹 Code with Short Comments
static bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];                          // sort by end time
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);

    int cnt = 1;                                  // count of non-overlapping intervals
    int lastendtime = intervals[0][1];            // end time of last chosen interval

    for (int i = 1; i < intervals.size(); i++) {  // start from 2nd interval
        if (intervals[i][0] >= lastendtime) {     // non-overlapping → select
            cnt++;
            lastendtime = intervals[i][1];        // update end time
        }
    }
    return intervals.size() - cnt;                // remove rest
}
