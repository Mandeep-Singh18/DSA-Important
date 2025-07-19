Short Approach for lastStoneWeight:
    Use a max-heap to simulate repeatedly smashing the two heaviest stones.
    If the stones are equal, both are destroyed.
    If not, push the remaining difference back into the heap.
    Repeat until one or zero stones remain.


int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxh;               // Max-heap to get heaviest stones

    for (int n : stones)
        maxh.push(n);                       // Push all stones into heap

    while (maxh.size() > 1) {
        int first = maxh.top(); maxh.pop(); // Heaviest stone
        int second = maxh.top(); maxh.pop(); // Second heaviest

        if (first != second)
            maxh.push(first - second);      // Push the remaining stone if not equal
    }

    return maxh.empty() ? 0 : maxh.top();   // Return last stone or 0
}
