      Check if at least k nodes remain.
      If yes, reverse the next k nodes.
      onnect the reversed group with the previous and next groups.
      Repeat until no more full groups of k.

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;           // Edge cases

    ListNode* curr = head;
    ListNode* newHead = nullptr;                // New head of the result
    ListNode* tail = nullptr;                   // Tail of the previous group

    while (curr) {
        // Step 1: Check if at least k nodes are left
        ListNode* temp = curr;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) {
            // Less than k nodes, connect as-is
            if (tail) tail->next = curr;
            break;
        }

        // Step 2: Reverse k nodes
        ListNode* groupHead = curr;
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        count = 0;

        while (curr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // Step 3: Connect reversed group
        if (!newHead) newHead = prev;           // Set new head on first group
        if (tail) tail->next = prev;            // Connect previous group
        tail = groupHead;                       // Update tail for next connection
    }

    return newHead ? newHead : head;            // Return final head
}
