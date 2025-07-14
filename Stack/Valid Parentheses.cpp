    Use a stack to keep track of opening brackets.
      For each character:
        If it’s an opening bracket, push it to the stack.
        If it’s a closing bracket, check if the top of the stack has the matching opening bracket.
        If yes, pop the top.
        If no or stack is empty, it's invalid.
      At the end, if the stack is empty → valid; otherwise → invalid.


bool isValid(string s) {
    stack<char> st;  // Stack to store opening brackets
    unordered_map<char, char> co = {
        {')', '('},   // Map each closing bracket to its corresponding opening
        {'}', '{'},
        {']', '['}
    };

    for (char c : s) {
        if (co.count(c)) {  // If current char is a closing bracket
            if (!st.empty() && st.top() == co[c]) {
                st.pop();  // Top matches expected opening → pop it
            } else {
                return false;  // Mismatch or stack empty → invalid
            }
        } else {
            st.push(c);  // Push opening bracket to stack
        }
    }

    return st.empty();  // Valid if no unmatched brackets remain
}
