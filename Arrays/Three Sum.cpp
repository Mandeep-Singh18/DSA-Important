vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans; // Vector to store the result triplets.

    int n = nums.size(); // Size of the input array.
    sort(nums.begin(), nums.end()); // Sort the array to facilitate the two-pointer approach.

    // Iterate through the array. We will fix one number and find the other two using two pointers.
    for (int i = 0; i < n; i++) {
        // Skip duplicate elements to avoid repeating triplets.
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1; // Left pointer, starting just after the fixed element.
        int k = n - 1; // Right pointer, starting from the end of the array.

        // Use two pointers to find two numbers that sum up to -nums[i].
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet.

            if (sum < 0) {
                // If sum is less than 0, increment the left pointer to increase the sum.
                j++;
            } else if (sum > 0) {
                // If sum is greater than 0, decrement the right pointer to decrease the sum.
                k--;
            } else {
                // If sum is zero, we found a valid triplet.
                ans.push_back({nums[i], nums[j], nums[k]});
                
                j++; // Move left pointer to the next element.
                // Skip duplicate elements to avoid repeating triplets.
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
            }
        }
    }

    return ans; // Return the list of all unique triplets.
}
