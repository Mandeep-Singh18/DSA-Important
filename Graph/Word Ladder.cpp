🧠 Short Approach
    Use BFS starting from beginWord.
    At each step, change one character to generate all valid next words in wordList.
    Track steps in BFS → first time reaching endWord gives shortest transformation.

⏱️ Time & Space Complexity
    Time: O(M × N × 26) → M = word length, N = number of words.
    Space: O(N) → for unordered_set and BFS queue.

💡 In short:
    BFS through all one-letter transformations → shortest path to endWord.

💻 Code (With Short Comments)
  
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;     
    q.push({beginWord, 1});        // word + step
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);           // remove beginWord

    while(!q.empty()){
        string word = q.front().first;
        int step = q.front().second;
        q.pop();

        if(word == endWord) return step; // reached target

        for(int i = 0; i < word.size(); i++){
            char orig = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){  // valid transformation
                    st.erase(word);             // mark visited
                    q.push({word, step+1});     // push next step
                }
            }
            word[i] = orig; // restore original char
        }
    }
    return 0; // no path found
}
