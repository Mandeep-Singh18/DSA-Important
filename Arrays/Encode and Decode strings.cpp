Encode: Convert each string to format: length#string, and append to result.
Decode: Read the length till #, extract the next length characters as a string, and repeat.


string encode(vector<string>& strs) {
    string res;
    for(const string& s : strs){
        res += to_string(s.size()) + '#' + s;  // Add length + '#' + string
    }
    return res;
}

vector<string> decode(string s) {
    vector<string> res;
    int i = 0;
    while(i < s.size()){
        int j = i;
        while(s[j] != '#') j++;                // Find delimiter '#'
        int len = stoi(s.substr(i, j - i));    // Extract length
        i = j + 1;                             // Move to start of string
        res.push_back(s.substr(i, len));       // Extract string of 'len' length
        i += len;                              // Move to next block
    }
    return res;
}
