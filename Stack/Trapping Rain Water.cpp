Short Approach: Trapping Rain Water (Two Pointers)

        Use two pointers l (left) and r (right) starting from both ends of the height array.
        Maintain leftmax and rightmax to track the highest walls from both sides.
        At each step:
        Move the pointer pointing to the shorter wall.
        Water trapped at current index = min(leftmax, rightmax) - height[i].
        keep adding this to ans until pointers meet.
  
👉 Efficient solution: O(n) time, O(1) space.


int trap(vector<int>& height) {
    if (height.empty()) return 0;                // No bars, no water

    int l = 0, r = height.size() - 1;             // Left and right pointers
    int ans = 0;                                  // Total trapped water
    int leftmax = height[l], rightmax = height[r]; // Max heights from both sides

    while (l < r) {
        if (leftmax < rightmax) {                // Left side is lower
            l++;                                  // Move left pointer
            leftmax = max(leftmax, height[l]);    // Update left max
            ans += leftmax - height[l];           // Water trapped at l
        } else {                                  // Right side is lower
            r--;                                  // Move right pointer
            rightmax = max(rightmax, height[r]);  // Update right max
            ans += rightmax - height[r];          // Water trapped at r
        }
    }

    return ans;  // Return total water trapped
}
