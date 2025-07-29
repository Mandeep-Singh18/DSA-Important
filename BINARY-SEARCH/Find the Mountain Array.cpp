// 🏔️ Problem: Find in Mountain Array (Leetcode Hard)

// 🧠 Simple Approach:
// A mountain array is like an array that goes up to a peak and then comes down.
// Our task is to find the index of a `target` in this special array using minimal calls to `get()`.

// ✅ Step-by-step Plan:
// 1. **Find the Peak** of the mountain using binary search.
// 2. **Binary Search in the Left (Increasing) part** of the array.
// 3. If not found, **Binary Search in the Right (Decreasing) part** of the array.
// 4. If the element is not in either side, return -1.


int findInMountainArray(int target, MountainArray &mountainArr) {
    int length = mountainArr.length();

    // 🔍 Step 1: Find the Peak index
    int l = 1, r = length - 2, peak = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        int left = mountainArr.get(m - 1);
        int mid = mountainArr.get(m);
        int right = mountainArr.get(m + 1);

        if (left < mid && mid < right) {
            l = m + 1;              // increasing → move right
        } else if (left > mid && mid > right) {
            r = m - 1;              // decreasing → move left
        } else {
            peak = m;               // found peak
            break;
        }
    }

    // 🔍 Step 2: Binary search on left (increasing part)
    l = 0;
    r = peak - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        int val = mountainArr.get(m);
        if (val < target) {
            l = m + 1;              // move right
        } else if (val > target) {
            r = m - 1;              // move left
        } else {
            return m;               // target found
        }
    }

    // 🔍 Step 3: Binary search on right (decreasing part)
    l = peak;
    r = length - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        int val = mountainArr.get(m);
        if (val > target) {
            l = m + 1;              // move right (since decreasing)
        } else if (val < target) {
            r = m - 1;              // move left
        } else {
            return m;               // target found
        }
    }

    return -1;                      // not found in either half
}
