<!-- Iterative Approach -->

```
  int search(vector<int>& nums, int target) {
    int st = 0, lst = nums.size() - 1;                // Initialize start and end pointers

    while (st <= lst) {                               // Loop until the search space is valid
        int mid = (st + lst) / 2;                    // Calculate the mid index

        if (target > nums[mid]) {                     // If target is greater than mid element
            st = mid + 1;                             // Narrow the search to the right half
        }
        else if (target < nums[mid]) {                // If target is less than mid element
            lst = mid - 1;                            // Narrow the search to the left half
        }
        else {                                        // Target is equal to mid element
            return mid;                               // Return the index of the target
        }
    }
    return -1;                                        // Return -1 if target is not found
}
  
```

<!-- Recursive Apptoach -->

  ```
    int binarySearchHelper(vector<int>& nums, int st, int lst, int target) {
    if (st > lst) {                                   // Base case: search space is invalid
        return -1;                                    // Return -1 if target is not found
    }

    int mid = (st + lst) / 2;                        // Calculate the mid index

    if (target > nums[mid]) {                         // If target is greater than mid element
        return binarySearchHelper(nums, mid + 1, lst, target);  // Recur for the right half
    }
    else if (target < nums[mid]) {                    // If target is less than mid element
        return binarySearchHelper(nums, st, mid - 1, target);   // Recur for the left half
    }
    else {                                            // Target is equal to mid element
        return mid;                                   // Return the index of the target
    }
}

int search(vector<int>& nums, int target) {
    return binarySearchHelper(nums, 0, nums.size() - 1, target); // Call the helper function with initial parameters
}

```
