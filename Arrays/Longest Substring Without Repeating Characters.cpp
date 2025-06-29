✅ Approach (Sliding Window using Set):
   // We maintain a window [l, r] (from left l to right r) that doesn't contain duplicate characters.
    // We use a set to track the characters in the current window.


int lengthOfLongestSubstring(string s) {
    unordered_set<char> cs;  // Set to store unique characters in current window
    int l = 0;               // Left pointer of window
    int ans = 0;             // Store max length of substring

    for(int r = 0; r < s.size(); r++) {          // Right pointer moves through the string
        while(cs.find(s[r]) != cs.end()) {       // If current char is already in set (duplicate)
            cs.erase(s[l]);                      // Remove leftmost char from set
            l++;                                 // Move left pointer forward
        }
        cs.insert(s[r]);                         // Insert current char into set
        ans = max(ans, r - l + 1);               // Update max length of substring
    }

    return ans;  // Return the longest substring length
}
