Short Approach: Sliding Window Maximum (Deque)
      Use a deque to keep track of indices of elements in the current window.
      Maintain the deque in decreasing order (front = max).
      At each step
      Remove indices from the back if their value is less than current.
      Remove indices from the front if they’re out of the current window.
      Once window size hits k, record the front of deque as the max.

✅ Time: O(n) (each element pushed/popped at most once)


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> output(n - k + 1);  // Result array
    deque<int> q;                   // Stores indices of useful elements
    int l = 0, r = 0;               // Left and right window pointers

    while (r < n) {
        while (!q.empty() && nums[q.back()] < nums[r]) {
            q.pop_back();          // Remove smaller elements from back
        }
        q.push_back(r);            // Add current index to deque

        if (l > q.front()) {
            q.pop_front();         // Remove out-of-window element
        }

        if ((r + 1) >= k) {        // Window has reached size k
            output[l] = nums[q.front()];  // Max is at front of deque
            l++;                   // Slide window
        }
        r++;                       // Move right pointer
    }

    return output;  // Return all max values from each window
}
