Short Approach to Merge K Sorted Linked Lists:

    Use a min-heap (priority queue) to always pick the node with the smallest value.
    Insert the first node of each list into the heap.
    Repeatedly extract the smallest node and insert its next node (if exists) into the heap.
    Link the extracted nodes to form the merged list.


class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap: smallest value has higher priority
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minh; // Min-heap for nodes
        for (auto node : lists) {
            if (node) minh.push(node); // Push first node of each list
        }

        ListNode* head = NULL;  // Head of merged list
        ListNode* tail = NULL;  // Tail to build the list

        while (!minh.empty()) {
            ListNode* curr = minh.top(); minh.pop(); // Get smallest node

            if (!head) head = tail = curr;           // First node case
            else tail->next = curr, tail = curr;     // Append node

            if (curr->next) minh.push(curr->next);   // Push next node if exists
        }

        return head; // Return merged list
    }
};
