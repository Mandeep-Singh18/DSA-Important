      Goal: Merge k sorted linked lists into one sorted list.
      Strategy: Use pairwise merging (like bottom-up merge sort) to reduce k lists to 1.
      Helper Function: mergeList() merges two sorted linked lists.


ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;                      // No lists to merge
    }

    while (lists.size() > 1) {
        vector<ListNode*> mergedLists;      // Temporary vector to store merged pairs
        for (int i = 0; i < lists.size(); i += 2) {
            ListNode* l1 = lists[i];
            ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;  // Handle odd-sized list
            mergedLists.push_back(mergeList(l1, l2)); // Merge two lists
        }
        lists = mergedLists;                // Update lists with merged result
    }

    return lists[0];                        // Final merged list
}

private:
ListNode* mergeList(ListNode* l1, ListNode* l2) {
    ListNode dummy;                         // Dummy node to simplify merge logic
    ListNode* tail = &dummy;                // Tail points to last node in merged list

    while (l1 && l2) {                      // Merge until one list is exhausted
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;                  // Move tail forward
    }

    tail->next = l1 ? l1 : l2;              // Append remaining list (if any)

    return dummy.next;                      // Return head of merged list
}
