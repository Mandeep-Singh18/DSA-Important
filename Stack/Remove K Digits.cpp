 Short Approach: Remove K Digits to Make Smallest Number
        Goal: Remove k digits from the number string num to get the smallest possible number.
        Use a monotonic increasing stack:
        If the current digit is smaller than the top of the stack and we still have digits to remove (k > 0), pop the top.
        After iterating, if k > 0, remove digits from the end (stack top).
        Build the result from the stack, remove leading zeros.
        If empty → return "0".
        ✅ Time: O(n), Space: O(n)

std::string removeKdigits(std::string num, int k) {
    std::stack<char> stack;  // To store digits of final number

    for (char digit : num) {
        while (!stack.empty() && k > 0 && stack.top() > digit) {
            stack.pop();     // Remove larger digit
            k--;             // Decrement digits to remove
        }
        stack.push(digit);   // Push current digit
    }

    while (k > 0 && !stack.empty()) {
        stack.pop();         // Remove remaining digits if needed
        k--;
    }

    std::string result;
    while (!stack.empty()) {
        result += stack.top();  // Build result from stack
        stack.pop();
    }

    std::reverse(result.begin(), result.end());  // Correct the order

    size_t pos = result.find_first_not_of('0');  // Remove leading zeros
    result = (pos == std::string::npos) ? "0" : result.substr(pos);

    return result;  // Return final number
}
