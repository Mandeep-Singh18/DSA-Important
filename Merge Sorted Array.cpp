✅ Approach (Start from the end):
   // Start comparing from the end of both arrays.
    //Put the largest elements at the end of nums1 (right to left).
    //This avoids overwriting the original values of nums1.


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int midx = m - 1;           // Pointer for last valid element in nums1
    int nidx = n - 1;           // Pointer for last element in nums2
    int right = m + n - 1;      // Pointer for the end position in nums1

    while (nidx >= 0) {         // Keep going until all elements in nums2 are merged
        if (midx >= 0 && nums1[midx] > nums2[nidx]) {
            nums1[right] = nums1[midx];  // Place larger of the two at the end
            midx--;                      // Move pointer in nums1
        } else {
            nums1[right] = nums2[nidx];  // Place element from nums2
            nidx--;                      // Move pointer in nums2
        }
        right--;                         // Move backward in nums1
    }    
}
