Use a hashmap to count frequencies and a max heap (priority queue) to sort characters by frequency.


string frequencySort(string s) {
    unordered_map<char, int> freq;         // Count frequency of each character
    for (char c : s) freq[c]++;            // Frequency map

    string res = "";
    while (!freq.empty()) {
        char maxChar = '\0';
        int maxFreq = 0;

        // Find the character with max frequency
        for (auto& [ch, count] : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                maxChar = ch;
            }
        }

        res.append(maxFreq, maxChar);      // Append the character maxFreq times
        freq.erase(maxChar);               // Remove it from map
    }

    return res;                            // Return final string
}
