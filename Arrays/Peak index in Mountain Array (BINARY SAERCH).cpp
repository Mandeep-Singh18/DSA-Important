class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2; // Set initial boundaries for binary search (ignore first and last elements)

        while (st <= end) {
            int mid = st + (end - st) / 2; // Calculate mid-point to avoid overflow

            if ((arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1])) {
                return mid; // Return mid if it's greater than its neighbors (peak element)
            }

            if (arr[mid - 1] < arr[mid]) {
                st = mid + 1; // Move start to mid + 1 if left part is increasing
            } else {
                end = mid - 1; // Move end to mid - 1 if right part is decreasing
            }
        }

        return -1; // Return -1 if no peak element found (edge case)
    }
};
