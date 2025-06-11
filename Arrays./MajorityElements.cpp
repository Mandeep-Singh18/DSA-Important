# Majority Element Finder (Boyer-Moore Voting Algorithm)

## 🧠 Problem Statement
Given an array of integers `nums`, find the element that appears more than `n / 2` times (if any).  
If such an element exists, return it; otherwise, return `-1`.

---

## ✅ Approach: Boyer-Moore Majority Vote Algorithm

### Simplified Steps:
1. **Find a candidate**:
   - Use a `count` variable to assume a majority element.
   - If `count == 0`, pick the current element as a new candidate.
   - If the current element equals the candidate, increment the count.
   - Otherwise, decrement the count.

2. **Verify the candidate**:
   - Count how many times the candidate appears in the array.
   - If it appears more than `n/2` times, it's the majority.
   - Otherwise, return `-1`.

---

## 🧮 Time & Space Complexity
- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

```
    int majorityElement(vector<int>& nums) {
    int count = 0; 
    int ele; // To store possible majority element

    // Step 1: Find the candidate
    for(int i = 0; i < nums.size(); i++) {
        if(count == 0) {
            ele = nums[i]; // Pick new candidate
            count = 1;     // Reset count
        }
        else if(nums[i] == ele) count++; // Same as candidate → increase count
        else count--;                    // Different → decrease count
    }

    // Step 2: Check if candidate is majority
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == ele) cnt++; // Count how many times candidate appears
    }

    if(cnt > nums.size() / 2) return ele; // If appears > n/2 → return it

    return -1; // Otherwise, no majority
}
```
