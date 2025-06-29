✅ Approach (Sliding Window):

      Expand the window by moving the right pointer j.
      Once the sum in the window is ≥ target, try to shrink the window from the left (l) to find the smallest possible length.

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0;                      // Left pointer of window
    int total = 0;                  // Current window sum
    int ans = INT_MAX;              // Store the minimum length found

    for(int j = 0; j < nums.size(); j++) {  // Right pointer of window
        total += nums[j];                   // Add current element to window sum

        while(total >= target) {            // While sum is enough (≥ target)
            ans = min(ans, j - l + 1);      // Update minimum length
            total -= nums[l];               // Shrink window from the left
            l++;
        }
    }

    return ans == INT_MAX ? 0 : ans;  // If not found, return 0. Else, return min length
}
