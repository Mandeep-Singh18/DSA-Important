void rotate(vector<int>& nums, int k) {
    k = k % nums.size();  // Handle cases when k > size of array

    // Step 1: Reverse the first part (from index 0 to size - k - 1)
    reverse(nums.begin(), nums.begin() + (nums.size() - k));  // reverse first part

    // Step 2: Reverse the second part (from index size - k to end)
    reverse(nums.begin() + (nums.size() - k), nums.end());    // reverse second part

    // Step 3: Reverse the whole array
    reverse(nums.begin(), nums.end());  // reverse entire array
}
