vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;  // Hash map to store elements and their indices
    
    // Iterate through the nums vector
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];  // Calculate the complement required to reach the target
        
        // Check if the complement exists in the map
        if (mpp.find(complement) != mpp.end()) {
            // If the complement exists, return the indices of the complement and the current element
            return {mpp[complement], i};
        }
        
        // Store the current element and its index in the map
        mpp[nums[i]] = i;
    }

    // Return an empty vector if no pair is found that sums up to the target
    return {};
}
