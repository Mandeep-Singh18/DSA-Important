Short Approach for MedianFinder:
      Use two heaps:
      Max-heap (maxheap): Stores smaller half of numbers.
      Min-heap (minheap): Stores larger half of numbers.
      Always balance the heaps so their sizes differ by at most 1.
      Median is:
      Middle of two heaps if sizes are equal.
      Top of the larger heap if sizes differ.


class MedianFinder {
private:
    priority_queue<int> maxheap;                         // Max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> minheap; // Min-heap for larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        maxheap.push(num);                               // Step 1: push to maxheap
        minheap.push(maxheap.top()); maxheap.pop();      // Step 2: move top to minheap

        if (minheap.size() > maxheap.size()) {           // Step 3: balance if needed
            maxheap.push(minheap.top()); minheap.pop();
        }
    }

    double findMedian() {
        if (maxheap.size() == minheap.size())            // Even: average of two middle
            return (maxheap.top() + minheap.top()) / 2.0;
        return maxheap.top();                            // Odd: top of maxheap
    }
};
