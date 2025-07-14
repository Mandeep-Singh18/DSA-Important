 Short Approach: Largest Rectangle in Histogram
      Use a monotonic increasing stack to store indices of bars.
      For each bar:
      If it’s taller than the bar on top of the stack, push its index.
      If it’s shorter, pop from stack and calculate area using popped height as the smallest bar.
      After the loop, process any remaining bars in the stack the same way.

✅ Efficient: O(n) time, O(n) space.


int largestRectangleArea(vector<int>& heights) {
    stack<int> stack;             // Stack to store indices
    stack.push(-1);               // Sentinel value for width calculation
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (stack.top() != -1 && heights[i] <= heights[stack.top()]) {
            int height = heights[stack.top()];     // Height of popped bar
            stack.pop();                           
            int width = i - stack.top() - 1;        // Width between current and new top
            max_area = max(max_area, height * width);  // Update max area
        }
        stack.push(i);                              // Push current bar index
    }

    while (stack.top() != -1) {
        int height = heights[stack.top()];          // Height of remaining bar
        stack.pop();
        int width = heights.size() - stack.top() - 1; // Width till end
        max_area = max(max_area, height * width);     // Update max area
    }

    return max_area;  // Return the largest rectangle area
}
