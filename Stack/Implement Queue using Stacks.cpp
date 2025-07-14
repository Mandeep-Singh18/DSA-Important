    We use two stacks s1 and s2 to simulate queue behavior (FIFO):
      push(x): Always push the element to s1. (Easy push)
      pop():
        If s2 is empty, transfer all elements from s1 to s2 (this reverses the order)
        Then pop from s2 (front of the queue).
      peek():
        Similar to pop(), but just return the top of s2 without removing it.
      empty(): Return true only if both s1 and s2 are empty.

class MyQueue {
private:
    std::stack<int> s1, s2;  // Two stacks: s1 for input, s2 for output

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);  // Always push to s1
    }

    int pop() {
        if (s2.empty()) {  // If s2 is empty, transfer elements from s1
            if (s1.empty()) {
                return NULL;  // Queue is empty
            }
            while (!s1.empty()) {
                s2.push(s1.top());  // Move top of s1 to s2
                s1.pop();
            }
        }
        int val = s2.top();  // Get front of queue (top of s2)
        s2.pop();            // Remove it
        return val;          // Return popped value
    }

    int peek() {
        if (s2.empty()) {  // If s2 is empty, transfer from s1
            if (s1.empty()) {
                return NULL;  // Queue is empty
            }
            while (!s1.empty()) {
                s2.push(s1.top());  // Move elements from s1 to s2
                s1.pop();
            }
        }
        return s2.top();  // Return front element without removing
    }

    bool empty() {
        return s1.empty() && s2.empty();  // Queue is empty if both stacks are empty
    }
};
