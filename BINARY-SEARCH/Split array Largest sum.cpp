// 📘 Problem: Split Array Largest Sum (Leetcode Hard)

// 🧠 Simple Approach:
// - We are given an array and a number `k`.
// - We need to split the array into exactly `k` or fewer parts.
// - Our goal is to **minimize the largest sum** among those `k` parts.

// ✅ How we solve it:
// 1. The smallest possible largest sum = the biggest number in the array.
// 2. The largest possible largest sum = sum of all numbers (no split).
// 3. We use **binary search** between those two values.
// 4. For each mid value (possible largest sum), we check:
//    - Can we split the array into ≤ `k` subarrays without any subarray sum > mid?
// 5. If yes → try smaller mid (to minimize).
//    If no → try bigger mid (need more room).
// 6. The smallest valid mid is the answer.


int splitArray(vector<int>& nums, int k) {
    int l = *max_element(nums.begin(), nums.end());    // smallest possible largest sum
    int r = accumulate(nums.begin(), nums.end(), 0);   // largest possible largest sum
    int res = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;                     // try middle value as max allowed sum
        if (canSplit(nums, k, mid)) {                  // can we split into ≤ k parts with this max?
            res = mid;                                 // yes, store result
            r = mid - 1;                               // try to minimize further
        } else {
            l = mid + 1;                               // no, need to allow bigger sum
        }
    }
    return res;                                        // minimum possible largest sum
}

private:
bool canSplit(vector<int>& nums, int k, int largest) {
    int subarray = 1, curSum = 0;                      // start with 1 subarray
    for (int num : nums) {
        curSum += num;                                 // keep adding to current subarray
        if (curSum > largest) {                        // if sum exceeds allowed max
            subarray++;                                // start a new subarray
            if (subarray > k) return false;            // too many subarrays? not allowed
            curSum = num;                              // start new subarray with current num
        }
    }
    return true;                                       // able to split within `k` parts
}
