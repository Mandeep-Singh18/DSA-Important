        We use a stack to evaluate the Reverse Polish Notation.
        Traverse each token from left to right.
        If the token is a number, push it to the stack.
        If the token is an operator (+, -, *, /), pop the top two numbers, apply the operation, and push the result back.
        After processing all tokens, the top of the stack is the final result.

int evalRPN(vector<string>& tokens) {
    stack<int> stack;  // Stack to store operands

    for (const string& c : tokens) {
        if (c == "+") {
            int a = stack.top(); stack.pop();  // Operand 1
            int b = stack.top(); stack.pop();  // Operand 2
            stack.push(b + a);  // Push result of b + a
        } else if (c == "-") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b - a);  // Push result of b - a
        } else if (c == "*") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b * a);  // Push result of b * a
        } else if (c == "/") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b / a);  // Push result of b / a
        } else {
            stack.push(stoi(c));  // Convert string to int and push
        }
    }

    return stack.top();  // Final result
}
