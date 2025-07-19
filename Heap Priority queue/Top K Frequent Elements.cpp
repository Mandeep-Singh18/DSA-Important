Short Approach for topKFrequent:
      Count the frequency of each number using a hash map.
      Use a min-heap to keep track of the top k elements by frequency.
      If heap size exceeds k, remove the element with the lowest frequency.
      Finally, extract the k most frequent elements from the heap.


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;                   // Map to store frequency
    for (int num : nums)
        count[num]++;

    // Min-heap: stores {frequency, number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;

    for (auto& entry : count) {
        heap.push({entry.second, entry.first});      // Push frequency and number
        if (heap.size() > k)
            heap.pop();                              // Remove least frequent
    }

    vector<int> res;
    while (!heap.empty()) {
        res.push_back(heap.top().second);            // Extract top k elements
        heap.pop();
    }

    return res;
}
