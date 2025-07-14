    We are given a circular array, and for each element, we need to find the next greater element.
    We simulate 2 rounds of the array using 2 * n - 1 → 0 loop to handle the circular nature.
    Use a monotonic stack to store candidates for the next greater element.
    For each index i (from right to left):
    Remove all elements from the stack that are ≤ current element.
    If we’re in the first round (i < n), record the answer: top of stack if not empty, else -1.
    Always push current element to the stack (as it might be next greater for someone on the left).


vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();              // Size of input array
    stack<int> st;                    // Stack to store next greater candidates
    vector<int> ans(nums.size());     // Result array

    for (int i = 2 * n - 1; i >= 0; i--) {           // Traverse twice for circular array
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();                                // Remove smaller/equal elements
        }
        if (i < n) {                                  // Only fill results in first pass
            ans[i] = st.empty() ? -1 : st.top();      // Top is next greater if stack not empty
        }
        st.push(nums[i % n]);                         // Push current element for next comparisons
    }
    return ans;  // Return the filled result
}
