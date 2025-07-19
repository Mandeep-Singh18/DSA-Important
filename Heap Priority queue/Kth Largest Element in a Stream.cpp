Short Approach for KthLargest:
    Maintain a min-heap of size k to keep track of the k largest elements.
    The top of the heap (minheap.top()) is always the Kth largest element.
    On eachadd(val):
    Insert val into the heap.
    If size exceeds k, remove the smallest element.
    Return the top of the heap.


class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minheap; // Min-heap to store k largest
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            minheap.push(n);            // Add number to heap
            if (minheap.size() > k)
                minheap.pop();          // Keep only k elements
        }
    }

    int add(int val) {
        minheap.push(val);              // Add new value
        if (minheap.size() > k)
            minheap.pop();              // Remove smallest if heap exceeds size
        return minheap.top();           // Kth largest = top of min-heap
    }
};
