We use a dummy node to build the new merged list. We compare nodes from both input lists one by one and add the smaller one to the result list. After one list ends, we link the remaining nodes from the other list.


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0); // Dummy node to start the merged list
    ListNode* temp = dummy;            // Pointer to build the new list

    while (list1 && list2) {           // While both lists have nodes
        if (list1->val < list2->val) {
            temp->next = list1;        // Add list1 node if smaller
            list1 = list1->next;       // Move list1 forward
        } else {
            temp->next = list2;        // Add list2 node if smaller
            list2 = list2->next;       // Move list2 forward
        }
        temp = temp->next;             // Move temp forward
    }

    if (list1) temp->next = list1;     // Attach remaining list1 nodes
    if (list2) temp->next = list2;     // Attach remaining list2 nodes

    return dummy->next;                // Return merged list (skipping dummy)
}
