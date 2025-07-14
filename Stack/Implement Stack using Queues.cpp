// Approach:
     Use two queues (q1, q2) to simulate stack behavior (LIFO).
     - push(): Simply enqueue to q1.
     - pop()/top(): Transfer all but last elements from q1 to q2 to access the last pushed element.
                    Then swap q1 and q2 to restore queue state for next operation.

class MyStack {
private:
    std::queue<int> q1;  // Main queue to hold elements
    std::queue<int> q2;  // Helper queue for pop and top operations

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);  // Add element to the end of q1
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());  // Move all but last element to q2
            q1.pop();
        }

        int poppedVal = q1.front();  // Last pushed element
        q1.pop();  // Remove it

        std::swap(q1, q2);  // Swap queues for next operation

        return poppedVal;  // Return popped value
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());  // Move all but last element to q2
            q1.pop();
        }

        int topVal = q1.front();  // Last pushed element (top of stack)
        q2.push(q1.front());  // Keep it for restoration
        q1.pop();

        std::swap(q1, q2);  // Restore state for next operation

        return topVal;  // Return top value
    }

    bool empty() {
        return q1.empty();  // Stack is empty if q1 is empty
    }
};
