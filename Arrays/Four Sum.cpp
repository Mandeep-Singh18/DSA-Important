vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); // Size of the input array.
    vector<vector<int>> res; // Vector to store the result quadruplets.
    sort(nums.begin(), nums.end()); // Sort the array to facilitate the two-pointer approach.

    // Iterate through the array for the first element of the quadruplet.
    for (int i = 0; i < n; i++) {
        // Skip duplicate elements for the first position to avoid repeating quadruplets.
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Iterate through the array for the second element of the quadruplet.
        for (int j = i + 1; j < n; j++) {
            // Skip duplicate elements for the second position to avoid repeating quadruplets.
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;

            // Set up two pointers for the remaining two elements.
            int k = j + 1; // Left pointer starts just after the second element.
            int l = n - 1; // Right pointer starts from the end of the array.

            // Use the two pointers to find the remaining two numbers that sum to the target.
            while (k < l) {
                long long sum = nums[i] + nums[j] + nums[k] + nums[l]; // Calculate the sum of the quadruplet.

                if (sum < target) {
                    // If the sum is less than the target, move the left pointer to the right to increase the sum.
                    k++;
                } else if (sum > target) {
                    // If the sum is greater than the target, move the right pointer to the left to decrease the sum.
                    l--;
                } else {
                    // If the sum matches the target, we found a valid quadruplet.
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    
                    k++; // Move the left pointer to the next element.
                    l--; // Move the right pointer to the previous element.

                    // Skip duplicate elements for the third position.
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    // Skip duplicate elements for the fourth position.
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
            }
        }
    }

    return res; // Return the list of all unique quadruplets that sum to the target.
}
