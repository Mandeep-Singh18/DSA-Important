Short Approach
      First, record the last occurrence index of each character in the string.
      Traverse the string while tracking:
      end: the farthest last index of any character seen so far.
      size: current partition size.
      When the current index i == end, we can close the partition and store its size.
      Repeat until the string ends.

vector<int> partitionLabels(string s) {
    unordered_map<char, int> lastIndex;        // store last occurrence of each char
    for (int i = 0; i < s.size(); i++) 
        lastIndex[s[i]] = i;

    vector<int> res;
    int size = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        size++;                                // grow current partition
        end = max(end, lastIndex[s[i]]);       // update partition boundary

        if (i == end) {                        // reached end of partition
            res.push_back(size);               // save partition size
            size = 0;                          // reset for next partition
        }
    }
    return res;
}
