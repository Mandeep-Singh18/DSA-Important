int maxSubArray(vector<int>& nums) {
    int sum = 0;                // Initialize the current sum to 0
    int maxi = INT_MIN;         // Initialize the maximum sum to the smallest possible integer value

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];         // Add the current element to the current sum
        maxi = max(maxi, sum);  // Update the maximum sum if the current sum is greater

        // If the current sum is negative, reset it to 0
        // as starting a new subarray from the next element might yield a higher sum.
        if(sum < 0) {           
            sum = 0;            // Reset the current sum to 0
        }
    }

    return maxi;                // Return the maximum sum found
}
