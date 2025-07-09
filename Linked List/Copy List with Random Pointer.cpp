          Create a copy of each node and store the mapping of original → copy in a hash map.
          Then use the map to set correct next and random pointers in copied nodes.


Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> oldtocopy; // Map original -> copy
    oldtocopy[NULL] = NULL;                // Handle null cases

    Node* cur = head;

    // Step 1: Create copy of each node
    while (cur != NULL) {
        Node* copy = new Node(cur->val);   // Create copy
        oldtocopy[cur] = copy;             // Store mapping
        cur = cur->next;
    }

    cur = head;

    // Step 2: Assign next and random pointers
    while (cur != NULL) {
        Node* copy = oldtocopy[cur];               // Get copied node
        copy->next = oldtocopy[cur->next];         // Set next pointer
        copy->random = oldtocopy[cur->random];     // Set random pointer
        cur = cur->next;
    }

    return oldtocopy[head];  // Return copied head
}
