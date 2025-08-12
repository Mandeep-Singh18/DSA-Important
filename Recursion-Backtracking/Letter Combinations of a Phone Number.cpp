
Approach:
    Backtracking to generate all possible letter combinations for a phone number.
    - Map each digit to corresponding letters (like on old phone keypads).
    - Recursively build strings by picking one letter for each digit.
    - Base case: when the current string length equals digits length, store it in result.


vector<string> res; // Stores all combinations
vector<string> digitToChar = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "qprs", "tuv", "wxyz"
};

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return res;     // Edge case: no digits
    backtrack(0, "", digits);           // Start from index 0 with empty string
    return res;
}

void backtrack(int i, string curStr, string &digits) {
    if (curStr.size() == digits.size()) { // Base case: built full combination
        res.push_back(curStr);
        return;
    }
    string chars = digitToChar[digits[i] - '0']; // Get possible letters for current digit
    for (char c : chars) {
        backtrack(i + 1, curStr + c, digits);    // Append letter & move to next digit
    }
}
