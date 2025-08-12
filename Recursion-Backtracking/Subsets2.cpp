Approach:
    Generates all subsets while avoiding duplicates.
    Steps:
    1. Sort the array so duplicates are adjacent.
    2. Use recursion + backtracking:
       - At each step, add the current subset (ds) to the answer.
       - Loop from current index to end:
           * Skip duplicates (if nums[i] == nums[i-1] and not at start of loop).
           * Include nums[i], recurse for next index.
           * Backtrack by removing last element.

void findsub(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
    ans.push_back(ds);  // Add current subset to result

    for (int i = ind; i < nums.size(); i++) {
        if (i != ind && nums[i] == nums[i - 1]) continue; // Skip duplicate elements

        ds.push_back(nums[i]);            // Include current element
        findsub(i + 1, nums, ans, ds);    // Recurse to next index
        ds.pop_back();                    // Backtrack: remove last element
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;  // Stores all unique subsets
    vector<int> ds;           // Current subset
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    findsub(0, nums, ans, ds);
    return ans;
}
