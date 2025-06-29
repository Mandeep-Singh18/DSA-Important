✅ Approach (Sliding Window + Frequency Arrays):

      Count the frequency of characters in s1.
      Slide a window of size s1.length() over s2 and check if the frequency of characters matches s1.


bool areVectorsEqual(vector<int> a, vector<int> b) {
    for(int i = 0; i < 26; i++) {
        if(a[i] != b[i]) return false;  // If any char count doesn't match, not a valid permutation
    }
    return true;  // All counts match, it's a valid permutation
}

public:
bool checkInclusion(string s1, string s2) {
    if(s2.size() < s1.size()) return false;  // s1 can't be a permutation if it's longer than s2

    vector<int> freqS1(26, 0);               // Frequency of each char in s1
    for(char c : s1) freqS1[c - 'a']++;

    vector<int> freqS2(26, 0);               // Frequency of current window in s2
    int i = 0, j = 0;

    while(j < s2.size()) {
        freqS2[s2[j] - 'a']++;               // Add current char to window

        if(j - i + 1 == s1.size()) {         // If window size == s1 size
            if(areVectorsEqual(freqS1, freqS2)) return true;  // Check if it's a valid permutation
        }

        if(j - i + 1 < s1.size()) {
            j++;                             // Expand window
        } else {
            freqS2[s2[i] - 'a']--;           // Shrink window from left
            i++; j++;
        }
    }

    return false;  // No permutation found
}
