          Move fast pointer n steps ahead.
          Move slow and fast together until fast reaches the end.
          slow now points to the node before the one to be deleted.
          Remove the nth node from the end.


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If fast is NULL, remove the head node
    if (fast == NULL) return head->next;

    // Move both pointers until fast reaches the end
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the node after slow
    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete(delNode);                // Free memory

    return head;                    // Return updated head
}
