🔹 Approach (Greedy)
          Keep track of the farthest index (maxReach) you can jump to.
          If at any point the current index i is greater than maxReach, return false (can't move further).
          Otherwise, update maxReach using i + nums[i].
          If the loop completes, return true (end is reachable).
          
          ⏱ Time & Space Complexity
          Time: O(n) (loop through array once)
          Space: O(1) (only one variable maxReach)


bool canJump(vector<int>& nums) {
    int maxReach = 0;                        // farthest index we can reach
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;      // can't reach this index
        maxReach = max(maxReach, i + nums[i]); // update farthest reachable
    }
    return true;                             // reached end successfully
}
