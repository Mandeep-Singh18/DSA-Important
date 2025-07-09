      Count the length of the list.
      Compute k % length to handle large k.
      If k % length == 0, return original head.
      Move to the (length - k)-th node — this becomes the new tail.
      Break the list and rotate:
      Set the new head.
      Connect the old tail to the old head.


ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;                      // Edge case: empty list

    int length = 1;
    ListNode* dummy = head;

    // Step 1: Find length and last node
    while (dummy->next) {
        dummy = dummy->next;
        length++;
    }

    int position = k % length;                   // Effective rotation
    if (position == 0) return head;              // No rotation needed

    ListNode* current = head;

    // Step 2: Move to the new tail (length - position - 1)
    for (int i = 0; i < length - position - 1; ++i) {
        current = current->next;
    }

    // Step 3: Break and reconnect the list
    ListNode* newHead = current->next;           // New head after rotation
    current->next = nullptr;                     // Break the list
    dummy->next = head;                          // Connect old tail to old head

    return newHead;                              // Return new head
}
