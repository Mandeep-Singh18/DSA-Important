Short Approach
      Sort all intervals by start time.
      Traverse intervals one by one:
      If ans is empty or current interval does not overlap with last merged interval → push it to result.
      Otherwise, merge by updating the end time with max(end times).
      Return the merged list.



🔹 Code with Short Comments
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());         // Step 1: sort by start
    vector<vector<int>> ans;

    for (int i = 0; i < intervals.size(); i++) {
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);              // no overlap → new interval
        } else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]); 
            // overlap → merge by extending end
        }
    }
    return ans;
}

🔹 Complexity
    Sorting: O(n log n)
    Traversal: O(n)
    ✅ Total: O(n log n)
    Space: O(n) for result
