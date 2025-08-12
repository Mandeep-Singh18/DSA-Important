Approach:
  Generate all permutations using recursion + backtracking.
  - At each index, swap the current element with each possible choice.
  - Recurse to fix the next index.
  - Backtrack by swapping back to restore original state.


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;             // Stores all permutations
    backtrack(nums, 0, res);
    return res;
}

void backtrack(vector<int>& nums, int idx, vector<vector<int>>& res) {
    if (idx == nums.size()) {             // Base case: one complete permutation
        res.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);         // Choose element for current position
        backtrack(nums, idx + 1, res);    // Recurse for next position
        swap(nums[idx], nums[i]);         // Backtrack to restore order
    }
}
