// 🔍 Problem: Find Median of Two Sorted Arrays (Leetcode Hard)

// 🧠 Simple Approach:
// We are given two sorted arrays. We need to find the median of the combined sorted array,
// but we must do this in O(log(min(n1, n2))) time.

// ✅ What we do:
// 1. Always binary search on the **smaller array** to make partitioning easier.
// 2. We try to divide both arrays into two halves:
//    - Left half contains first half of all elements (up to the median).
//    - Right half contains the rest.
// 3. We make sure that the biggest element on the left half is <= the smallest on the right half.
// 4. If that condition is met:
//    - If total length is odd → median is max(left parts).
//    - If total length is even → median is average of max(left parts) and min(right parts).
// 5. If the left part of nums1 is too big → move search left.
//    If too small → move search right.


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();

    if (n1 > n2)                                  // Always binary search the smaller array
        return findMedianSortedArrays(nums2, nums1);

    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2;                 // Number of elements on the left half
    int low = 0, high = n1;

    while (low <= high) {
        int mid1 = (low + high) >> 1;             // Mid of nums1
        int mid2 = left - mid1;                   // Remaining elements from nums2

        int l1 = INT_MIN, l2 = INT_MIN;           // Left part maxes
        int r1 = INT_MAX, r2 = INT_MAX;           // Right part mins

        if (mid1 < n1) r1 = nums1[mid1];          // Right of partition in nums1
        if (mid2 < n2) r2 = nums2[mid2];          // Right of partition in nums2
        if (mid1 > 0) l1 = nums1[mid1 - 1];        // Left of partition in nums1
        if (mid2 > 0) l2 = nums2[mid2 - 1];        // Left of partition in nums2

        if (l1 <= r2 && l2 <= r1) {               // Valid partition found
            if (n % 2 == 1)
                return max(l1, l2);               // Odd total length → max of left part
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0; // Even → average of mid values
        }
        else if (l1 > r2) {
            high = mid1 - 1;                      // Move left in nums1
        }
        else {
            low = mid1 + 1;                       // Move right in nums1
        }
    }

    return 0;                                     // Should never reach here if input is valid
}
