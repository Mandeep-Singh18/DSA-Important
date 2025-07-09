      Use a doubly linked list to keep track of usage order:
      Right is the most recently used (MRU) end.
      Left is the least recently used (LRU) end.
      Use a hash map (cache) to access nodes in O(1) time.
      On get():
      If key exists, move the node to MRU end.
      On put():
      If key exists, remove old node.
      Insert new node at MRU end.
      If size exceeds capacity, remove LRU node from list and map.


class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> cache; // Key -> Node
    int cap;
    Node* left;   // Dummy LRU node
    Node* right;  // Dummy MRU node

    // Insert node at MRU end (before right)
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

    // Remove node from its position
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

public:
    // Constructor
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);         // Dummy LRU
        right = new Node(0, 0);        // Dummy MRU
        left->next = right;
        right->prev = left;
    }

    // Get value if key exists, else -1
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* getnode = cache[key];
            remove(getnode);           // Remove from current position
            insert(getnode);           // Move to MRU
            return getnode->val;
        }
        return -1;
    }

    // Insert or update key-value pair
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);        // Remove old node
        }
        Node* putnode = new Node(key, value);
        cache[key] = putnode;
        insert(putnode);               // Insert at MRU end

        if (cache.size() > cap) {
            Node* lru = left->next;    // First real node = LRU
            remove(lru);               // Remove from list
            cache.erase(lru->key);     // Remove from map
            delete lru;                // Free memory
        }
    }
};
