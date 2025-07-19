Idea:
Use a min-heap of size k.
Keep only the k largest elements in the heap.
The top of the min-heap is the Kth largest element.

🕒 Time Complexity:
O(n * log k) where n = nums.size()

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minheap; // Min-heap to store k largest elements
    for (int n : nums) {
        minheap.push(n);             // Push current element into min-heap
        if (minheap.size() > k)      // If heap size exceeds k, remove smallest
            minheap.pop();
    }
    return minheap.top();            // Top of min-heap is the Kth largest
}
