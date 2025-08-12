/*
Approach:
    Use recursion + backtracking to generate all subsets.
    At each index, we have two choices:
    1. Include the current element.
    2. Exclude the current element.
    Repeat until all elements are processed.


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;     // Stores all subsets
    vector<int> subset;          // Current subset being built

    createSubset(nums, 0, res, subset);
    return res;        
}

void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
    if (index == nums.size()) {      // Base case: reached end
        res.push_back(subset);       // Add current subset to result
        return;
    }

    subset.push_back(nums[index]);   // Include current element
    createSubset(nums, index + 1, res, subset);

    subset.pop_back();               // Backtrack: remove last element
    createSubset(nums, index + 1, res, subset); // Exclude current element
}
