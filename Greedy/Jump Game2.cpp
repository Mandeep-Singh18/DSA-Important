Short Approach
      Use two pointers l and r to track the current range reachable with the current number of jumps.
      Find the farthest index we can reach within that range.
      Move to the next range (l = r+1, r = farthest) and increment jumps.
      Continue until we reach the end.
        ⏱ Time: O(n)
        📦 Space: O(1)

int jump(vector<int>& nums) {
    int jumps = 0, l = 0, r = 0;                  // jumps taken, current range [l,r]
    while (r < nums.size() - 1) {                 // until last index is reachable
        int farthest = 0;                         
        for (int i = l; i <= r; i++)              // check all indices in current range
            farthest = max(farthest, i + nums[i]); // update farthest reach
        l = r + 1;                                // move to next range
        r = farthest;
        jumps++;                                  // increment jump count
    }
    return jumps;                                 // minimum jumps to reach end
}


