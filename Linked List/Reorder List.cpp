          Find the middle of the list using slow & fast pointers.
          Reverse the second half of the list.
          Merge the two halves alternately.


void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    // Step 1: Find middle of the list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half of the list
    ListNode* second = slow->next;
    ListNode* prev = slow->next = nullptr;
    while (second != nullptr) {
        ListNode* tmp = second->next;
        second->next = prev;
        prev = second;
        second = tmp;
    }

    // Step 3: Merge two halves
    ListNode* first = head;
    second = prev;
    while (second != nullptr) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;        // Link first -> second
        second->next = tmp1;         // Link second -> next of first

        first = tmp1;                // Move first forward
        second = tmp2;               // Move second forward
    }
}
