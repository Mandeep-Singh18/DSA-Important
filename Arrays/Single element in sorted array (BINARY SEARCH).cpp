int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size(); // Get the size of the array
    int st = 0, end = n - 1; // Set initial boundaries for binary search

    if (n == 1) return nums[0]; // If there's only one element, return it as the answer

    while (st <= end) {
        int mid = st + (end - st) / 2; // Calculate mid-point to avoid overflow

        if ((mid == 0) && (nums[0] != nums[1])) return nums[mid]; // If first element is unique, return it
        if ((mid == n - 1) && (nums[n - 1] != nums[n - 2])) return nums[mid]; // If last element is unique, return it

        if ((nums[mid - 1] != nums[mid]) && (nums[mid + 1] != nums[mid])) return nums[mid]; // If mid element is unique, return it

        if (mid % 2 == 0) { // If mid index is even
            if (nums[mid - 1] == nums[mid]) {
                end = mid - 1; // Move end to mid - 1 if left part is paired
            } else {
                st = mid + 1; // Move start to mid + 1 if left part is not paired
            }
        } else { // If mid index is odd
            if (nums[mid - 1] == nums[mid]) {
                st = mid + 1; // Move start to mid + 1 if left part is paired
            } else {
                end = mid - 1; // Move end to mid - 1 if left part is not paired
            }
        }
    }
    
    return -1; // Return -1 if no unique element found (edge case)
}
