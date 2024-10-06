int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;    // Initialize two pointers, left at the start, right at the end
    int maxwater = 0;                           // Variable to store the maximum water

    while (left < right) {                      // Continue until the two pointers meet
        int h = min(height[left], height[right]); // Get the minimum height between left and right
        int w = right - left;                   // Calculate the width between the two pointers
        int currentwater = h * w;               // Calculate the current water area (height * width)
        maxwater = max(maxwater, currentwater); // Update maxwater if the current area is larger

        if (height[left] < height[right])       // Move the pointer pointing to the shorter height
            left++;                             // Move left pointer right if left is shorter
        else
            right--;                            // Move right pointer left if right is shorter
    }

    return maxwater;                            // Return the maximum water found
}
