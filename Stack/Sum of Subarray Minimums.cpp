Short Approach: Sum of Subarray Minimums (Monotonic Stack)

          For each element arr[i], calculate:
          How many subarrays it is the minimum of.
          To do this, use two passes:
          prev[i]: Number of elements before i (including i) for which arr[i] is the minimum.
          next[i]: Number of elements after i (including i) for which arr[i] is the minimum.
          The contribution of arr[i] is:
          👉 arr[i] * prev[i] * next[i]
          Add up all contributions modulo 1e9+7.
          Use monotonic increasing stack to find previous and next less elements efficiently.


int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;               // Modulo value for result
    int n = arr.size();
    stack<int> st;                         // Monotonic stack
    vector<int> prev(n), next(n);         // Distances to previous and next less elements

    // Calculate prev[i]: distance to previous smaller element
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();   // Strictly greater
        prev[i] = st.empty() ? i + 1 : i - st.top();               // If none, take full length
        st.push(i);                                                // Push current index
    }
    st = stack<int>();  // Reset stack

    // Calculate next[i]: distance to next smaller or equal element
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();  // Greater or equal
        next[i] = st.empty() ? n - i : st.top() - i;               // If none, take full length
        st.push(i);                                                // Push current index
    }

    long res = 0;
    for (int i = 0; i < n; ++i) {
        // Each arr[i] contributes arr[i] * prev[i] * next[i] to result
        res = (res + (long)arr[i] * prev[i] * next[i]) % MOD;
    }

    return (int)res;  // Return final result
}
