✅ Approach (Two Pointers):
  //We use two pointers (l and r) from both ends, and keep track of the maximum height on both sides.
  //Water trapped at a position = min(leftmax, rightmax) - current height


int trap(vector<int>& height) {
    if(height.empty()) return 0;                    // No bars, no water

    int l = 0, r = height.size() - 1;               // Two pointers from both ends
    int ans = 0;                                    // Total water trapped
    int leftmax = height[l], rightmax = height[r];  // Max height on both sides

    while(l < r) {
        if(leftmax < rightmax) {                    // Process left side if leftmax is smaller
            l++;                                     // Move left pointer
            leftmax = max(leftmax, height[l]);       // Update leftmax
            ans += leftmax - height[l];              // Water trapped at l = leftmax - height[l]
        } else {                                     // Process right side
            r--;                                     // Move right pointer
            rightmax = max(rightmax, height[r]);     // Update rightmax
            ans += rightmax - height[r];             // Water trapped at r = rightmax - height[r]
        }
    }

    return ans;                                      // Return total water trapped
}
