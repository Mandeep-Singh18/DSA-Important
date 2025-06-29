✅ Approach (Sliding Window + Frequency Map):

      //  We use a sliding window and a frequency map to:
      // Track character counts inside the window
      // Only keep windows where at most k replacements are needed to make all characters the same.


int characterReplacement(string s, int k) {
    unordered_map<char, int> freq;  // To count characters in the current window
    int l = 0, maxf = 0;            // l = left pointer, maxf = max frequency in window
    int ans = 0;                    // Stores result

    for(int r = 0; r < s.size(); r++) {   // r = right pointer
        freq[s[r]]++;                    // Increase count of current char
        maxf = max(maxf, freq[s[r]]);    // Update max frequency of any char in window

        // If replacements needed > k, shrink the window
        while((r - l + 1) - maxf > k) {
            freq[s[l]]--;                // Remove the leftmost char from window
            l++;                         // Move left pointer
        }

        ans = max(ans, r - l + 1);       // Update result with current window size
    }

    return ans;  // Return longest valid window length
}
