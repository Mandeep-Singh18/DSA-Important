Short Approach for kClosest:
    Use a min-heap to store all points sorted by their Euclidean distance from origin.
    Distance is compared using squared value: x² + y² (no need to compute square root).
    Extract the top k closest points from the heap.


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Custom comparator: compare based on distance squared from origin
    auto comp = [](const vector<int>& a, const vector<int>& b) {
        return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

    for (const auto& point : points)
        minHeap.push(point);                     // Push all points into min-heap

    vector<vector<int>> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(minHeap.top());        // Extract top k closest points
        minHeap.pop();
    }

    return result;
}
