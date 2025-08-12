
Approach:
    Find all combinations of numbers that sum to target.
    - At each index, we have 2 choices:
      1. Include current element (if <= target) and stay at same index (can reuse element).
      2. Exclude current element and move to next index.
    - Use recursion + backtracking to explore all valid combinations.


void findsum(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (ind == arr.size()) {        // Base case: reached end of array
        if (target == 0) {          // Found valid combination
            ans.push_back(ds);
        }
        return;
    }

    if (arr[ind] <= target) {       // Include current element if possible
        ds.push_back(arr[ind]);
        findsum(ind, target - arr[ind], arr, ans, ds); // Stay at same index (reuse allowed)
        ds.pop_back();              // Backtrack
    }

    findsum(ind + 1, target, arr, ans, ds); // Exclude current element
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;  // Stores all combinations
    vector<int> ds;           // Current combination
    findsum(0, target, candidates, ans, ds);
    return ans;
}
