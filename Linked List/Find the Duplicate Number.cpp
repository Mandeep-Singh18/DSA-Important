            Treat the array like a linked list where nums[i] points to the next index.
            Since there is one duplicate, a cycle is guaranteed.
            Use slow and fast pointers to detect the cycle.
            Then, reset slow to start and move both one step at a time to find the duplicate (entry point of cycle).

int findDuplicate(std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Step 1: Detect cycle using slow and fast pointers
    do {
        slow = nums[slow];           // Move slow 1 step
        fast = nums[nums[fast]];     // Move fast 2 steps
    } while (slow != fast);          // Loop until they meet

    // Step 2: Find the entry point of the cycle (duplicate)
    slow = nums[0];                  // Reset slow to start
    while (slow != fast) {
        slow = nums[slow];          // Move both 1 step
        fast = nums[fast];
    }

    return slow;                    // Duplicate number
}
