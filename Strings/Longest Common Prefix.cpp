Sort the array of strings.
Only the first and last strings matter (they will differ the most).
Compare characters of the first and last string until they mismatch.
The common prefix up to that point is the answer.


string longestCommonPrefix(vector<string>& v) {
    sort(v.begin(), v.end());                   // Step 1: Sort the strings
    string first = v[0];                        // Step 2: First string after sort
    string last = v.back();                     // Step 3: Last string after sort
    string ans = "";

    for (int i = 0; i < min(first.size(), last.size()); ++i) {
        if (first[i] != last[i]) break;         // Stop if characters don't match
        ans += first[i];                        // Add matching characters to result
    }

    return ans;                                 // Return the common prefix
}
