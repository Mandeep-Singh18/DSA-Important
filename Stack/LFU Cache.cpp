Short Approach: LFU (Least Frequently Used) Cache
      Use two maps:
        mpp: key → Node (stores value & frequency)
      freqListMap: frequency → Doubly Linked List of nodes with that frequency
      When a node is accessed:
        Remove it from its current frequency list.
        Increase its frequency and move it to the new list.
        Update minfreq if needed.
      When capacity is full and a new key needs to be added:
        Remove least frequently used and least recently used node from minfreq list.
      Doubly linked list ensures O(1) insert/delete.

✅ Time Complexity:
get() and put() → O(1) on average


class Node {
public:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;

    Node(int key1, int val1) {
        key = key1;
        val = val1;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

class List {
public:
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(-1, -1);       // Dummy head
        tail = new Node(-1, -1);       // Dummy tail
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addfront(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        size--;
    }
};

class LFUCache {
    map<int, Node*> mpp;               // Key to Node
    map<int, List*> freqListMap;       // Frequency to List
    int Capacity;
    int minfreq;
    int maxcachesize;

public:
    LFUCache(int capacity) {
        Capacity = capacity;
        maxcachesize = capacity;
        minfreq = 0;
    }

    void update(Node* node) {
        if (freqListMap.find(node->cnt) != freqListMap.end()) {
            freqListMap[node->cnt]->removeNode(node);             // Remove from old freq list

            if (node->cnt == minfreq && freqListMap[node->cnt]->size == 0) {
                minfreq++;                                        // Update minfreq if list empty
            }

            int newcnt = ++node->cnt;                             // Increase freq
            List* newlist;

            if (freqListMap.find(newcnt) != freqListMap.end()) {
                newlist = freqListMap[newcnt];                    // Reuse existing list
            } else {
                newlist = new List();                              // Create new list
                freqListMap[newcnt] = newlist;
            }

            newlist->addfront(node);                              // Add node to new freq list
        }
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;               // Not found
        Node* node = mpp[key];
        update(node);                                            // Update frequency
        return node->val;
    }

    void put(int key, int value) {
        if (maxcachesize == 0) return;                           // No capacity

        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;                                   // Update value
            update(node);                                        // Update freq
        } else {
            if (Capacity == 0) {
                List* list = freqListMap[minfreq];               // Get least freq list
                if (list->size > 0) {
                    Node* lruNode = list->tail->prev;            // Least recently used
                    list->removeNode(lruNode);                   // Remove it
                    mpp.erase(lruNode->key);                     // Remove from map
                    Capacity++;

                    if (list->size == 0) {
                        freqListMap.erase(minfreq);              // Remove empty list
                        minfreq++;                               // Increase minfreq
                    }
                }
            }

            minfreq = 1;
            List* list = new List();

            if (freqListMap.find(1) != freqListMap.end()) {
                list = freqListMap[1];                           // Reuse list if exists
            } else {
                freqListMap[1] = list;                           // Create new freq list
            }

            Node* node = new Node(key, value);
            list->addfront(node);                                // Add new node to list
            mpp[key] = node;                                     // Map key to node
            Capacity--;
        }
    }
};
