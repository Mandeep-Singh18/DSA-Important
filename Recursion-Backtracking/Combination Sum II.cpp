
Approach:
    Find all unique combinations that sum to target (each element used at most once).
    - Sort array to group duplicates and allow early stopping.
    - At each step:
        1. Skip duplicates: if current number is same as previous and not first in loop.
        2. Stop loop early if current number > target (sorted array).
        3. Include current element, recurse with i+1 (no reuse).
        4. Backtrack by removing last element.


void findsum(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (target == 0) {                 // Found valid combination
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1]) continue; // Skip duplicates
        if (arr[i] > target) break;    // Early stop (sorted array)

        ds.push_back(arr[i]);          // Include current element
        findsum(i + 1, target - arr[i], arr, ans, ds); // Move to next index
        ds.pop_back();                 // Backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates & prune search
    vector<vector<int>> ans;   // Stores all unique combinations
    vector<int> ds;            // Current combination
    findsum(0, target, candidates, ans, ds);
    return ans;
}
