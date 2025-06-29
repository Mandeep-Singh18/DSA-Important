✅ Approach (Using Deque):

      We use a deque (double-ended queue) to keep track of indices of potential maximum elements in the current window:
      It stores indices in decreasing order of values.
      The front of the deque always contains the index of the maximum element in the current window.


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> output(n - k + 1);     // To store max for each window
    deque<int> q;                      // Deque to store indices of potential max elements
    int l = 0, r = 0;                  // Left and right pointers

    while (r < n) {
        // Remove all smaller elements from the back of the deque
        while (!q.empty() && nums[q.back()] < nums[r]) {
            q.pop_back();              // They can’t be the max anymore
        }
        q.push_back(r);                // Add current index to deque

        // Remove the front if it's outside the current window
        if (l > q.front()) {
            q.pop_front();
        }

        // If we have processed at least k elements, start recording results
        if ((r + 1) >= k) {
            output[l] = nums[q.front()]; // The front of deque is the max of the window
            l++;                         // Slide the window forward
        }

        r++; // Move right pointer
    }

    return output;  // Return the list of maximums for each window
}
