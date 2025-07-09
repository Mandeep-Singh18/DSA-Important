✅ Approach (Iterative Method – Using Three Pointers)

          We use three pointers:
                  curr to track the current node,
                  prev to keep the reversed part,
                  temp to store the next node before breaking the link.
          At each step, we reverse the current node's link, move the pointers forward, and repeat until the list is reversed.
        

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;     // Previous node (initially null)
    ListNode* curr = head;        // Current node

    while (curr) {
        ListNode* temp = curr->next; // Store next node
        curr->next = prev;           // Reverse current node's pointer
        prev = curr;                 // Move prev forward
        curr = temp;                 // Move curr forward
    }
    return prev;                   // New head of reversed list
}
