✅ Approach (Sliding Window + Hash Maps):

      Count how many times each character appears in t.
      Use a sliding window to find the smallest valid window in s that contains all required characters.
      Expand the window with the right pointer r, and once the window is valid, try to shrink it from the left to find the smallest length.


string minWindow(string s, string t) {
    if (t.empty()) return "";  // Edge case: if t is empty, return empty string

    unordered_map<char, int> countT, window;  // Frequency maps
    for (char c : t) {
        countT[c]++;          // Count frequency of each character in t
    }

    int have = 0, need = countT.size();       // 'have' tracks how many required chars we fully have
    pair<int, int> res = {-1, -1};            // To store the result window indices
    int resLen = INT_MAX;                     // To track the length of the smallest window
    int l = 0;                                // Left pointer of the sliding window

    for (int r = 0; r < s.length(); r++) {    // Right pointer moves through s
        char c = s[r];
        window[c]++;                          // Add current char to window

        if (countT.count(c) && window[c] == countT[c]) {
            have++;                           // We have enough of one required character
        }

        while (have == need) {                // All required chars are in window
            if ((r - l + 1) < resLen) {       // Update result if this window is smaller
                resLen = r - l + 1;
                res = {l, r};
            }

            window[s[l]]--;                   // Try to shrink window from left
            if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                have--;                       // Lost a required character count
            }
            l++;                              // Move left pointer forward
        }
    }

    return resLen == INT_MAX ? "" : s.substr(res.first, resLen);  // Return final substring
}
