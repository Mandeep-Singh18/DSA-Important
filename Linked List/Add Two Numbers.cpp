        Traverse both linked lists from start to end.
        At each step, add corresponding digits and carry.
        Create a new node with the sum's unit digit.
        Keep track of carry for the next step.
        At the end, if a carry is left, create one final node.


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);   // Dummy node to start result list
    ListNode* cur = dummy;               // Pointer to build the result list
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int carry = 0;

    while (t1 != NULL || t2 != NULL || carry) {
        int sum = carry;                 // Start with carry from last digit
        if (t1) sum += t1->val;          // Add digit from l1
        if (t2) sum += t2->val;          // Add digit from l2

        ListNode* sumnode = new ListNode(sum % 10); // Create node with unit digit
        carry = sum / 10;                           // Update carry
        cur->next = sumnode;                        // Link to result
        cur = cur->next;                            // Move to next

        if (t1) t1 = t1->next;           // Move l1 forward
        if (t2) t2 = t2->next;           // Move l2 forward
    }

    return dummy->next;                 // Return head of the result list
}
