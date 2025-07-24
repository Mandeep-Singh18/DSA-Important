string reverseWords(string s) {
    reverse(s.begin(), s.end()); // Step 1: Reverse the whole string
    int n = s.size(), i = 0;
    string ans = "";

    while (i < n) {
        while (i < n && s[i] == ' ') i++;          // Skip leading spaces
        if (i >= n) break;

        string word = "";
        while (i < n && s[i] != ' ') word += s[i++]; // Collect the word

        reverse(word.begin(), word.end());         // Reverse the word back to correct order
        if (!ans.empty()) ans += " ";              // Add space between words
        ans += word;                               // Append word to result
    }

    return ans; // Final string with reversed word order
}
