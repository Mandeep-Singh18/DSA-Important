          We use a monotonic stack to solve this in linear time.
          For each day i, we want to find the next day j such that temperatures[j] > temperatures[i].
          We use a stack to keep track of indices of unresolved temperatures in decreasing order.
          While the current temperature is greater than the top of the stack, we've found the answer for that earlier index.
          We then compute the number of days and store it in the result array.


vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);  // Initialize result array with 0
    stack<pair<int, int>> stack;  // Monotonic stack: {temperature, index}

    for (int i = 0; i < temperatures.size(); i++) {
        int t = temperatures[i];  // Current temperature

        // While current temp is greater than the one on top of the stack
        while (!stack.empty() && t > stack.top().first) {
            auto pair = stack.top(); stack.pop();  // Pop the lower temperature
            res[pair.second] = i - pair.second;    // Days until warmer temperature
        }

        stack.push({t, i});  // Push current temp with its index
    }

    return res;  // Final result
}
