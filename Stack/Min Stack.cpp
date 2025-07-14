Approach    Use two stacks
            st to store all elements.
            minst to store the minimum element at every point.
            When pushing, push the element to st, and the min(val, minst.top()) to minst.
            When popping, pop from both stacks.
            The top of minst always gives the current minimum in constant time.


class MinStack {
private:
    stack<int> st;     // Main stack to store all values
    stack<int> minst;  // Stack to keep track of current minimums

public:
    MinStack() {}

    void push(int val) {
        st.push(val);  // Push value to main stack
        if (!minst.empty()) {
            val = min(val, minst.top());  // Update min if needed
        }
        minst.push(val);  // Push current min to min stack
    }

    void pop() {
        st.pop();      // Pop from main stack
        minst.pop();   // Pop from min tracking stack
    }

    int top() {
        return st.top();  // Return top of main stack
    }

    int getMin() {
        return minst.top();  // Return current minimum (top of min stack)
    }
};
