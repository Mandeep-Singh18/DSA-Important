Approach:     Use two pointers: slow (1 step) and fast (2 steps).
              If there's a cycle, fast and slow will eventually meet.
              If fast reaches the end, there's no cycle.


bool hasCycle(ListNode* head) {
    ListNode* fast = head;             // Fast pointer (moves 2 steps)
    ListNode* slow = head;             // Slow pointer (moves 1 step)

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;       // Move fast 2 steps
        slow = slow->next;             // Move slow 1 step

        if (fast == slow) {            // If they meet, cycle exists
            return true;
        }
    }

    return false;                      // If fast reaches end, no cycle
}
