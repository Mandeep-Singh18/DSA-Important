      You're given two arrays:
      nums2 is the reference array.
      nums1 is a subset of nums2; for each element in nums1, find its next greater element in nums2.
      Use a monotonic stack to preprocess nums2 from right to left:
      Mantain a stack of greater elements.
      For each element, map it to its next greater in a hashmap.
      Then, for each element in nums1, simply look up the result in the map.

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;                             // Result vector
    unordered_map<int, int> mpp;                 // Map: element -> next greater
    stack<int> st;                               // Stack to find next greater

    int i = nums2.size() - 1;                    // Start from the end of nums2

    while (i >= 0) {
        int x = nums2[i];                        // Current element

        while (!st.empty() && st.top() < x) {
            st.pop();                            // Pop smaller elements
        }

        if (st.empty()) {
            mpp[x] = -1;                         // No greater element
        } else {
            mpp[x] = st.top();                   // Top is next greater
        }

        st.push(x);                              // Push current element
        i--;
    }

    for (int el : nums1) {
        ans.push_back(mpp[el]);                  // Lookup next greater from map
    }

    return ans;                                  // Return the result
}
