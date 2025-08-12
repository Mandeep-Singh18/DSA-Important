
Approach:
    Backtracking to generate all palindrome partitions of a string.
    - Start from index 0, try every possible substring.
    - If substring is a palindrome, add it to current partition and recurse for the rest.
    - Backtrack by removing last substring after exploring.
    - Use helper function isPali() to check palindrome.


vector<vector<string>> partition(string s) {
    vector<vector<string>> res;    // Stores all partitions
    vector<string> part;           // Current partition
    dfs(0, s, part, res);
    return res;
}

private:
void dfs(int i, const string& s, vector<string>& part, vector<vector<string>>& res) {
    if (i >= s.length()) {         // Base case: reached end of string
        res.push_back(part);
        return;
    }
    for (int j = i; j < s.length(); j++) {
        if (isPali(s, i, j)) {     // Check if substring is palindrome
            part.push_back(s.substr(i, j - i + 1)); // Choose substring
            dfs(j + 1, s, part, res);               // Explore further
            part.pop_back();       // Backtrack
        }
    }
}

bool isPali(const string& s, int l, int r) {
    while (l < r) {                // Two-pointer palindrome check
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
