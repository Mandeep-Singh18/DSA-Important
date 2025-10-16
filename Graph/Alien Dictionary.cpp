🧠 Short Approach
    Build a graph of character precedence from consecutive words.
    Use Kahn’s Algorithm (BFS Topological Sort) to find a valid character order.
    If cycle exists → return empty string.

⏱️ Time & Space Complexity
    Time: O(C + W)→ C = total characters, W = number of words.
    Space: O(C + W) → adjacency list + indegree + queue.

💡 In short:
    Construct character graph → BFS topological sort → valid alien dictionary order.

💻 Code (With Short Comments)

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj; // graph
        unordered_map<char,int> indegree;             // indegrees

        // Initialize nodes
        for(string w : words)
            for(char c : w) {
                adj[c] = {};
                indegree[c] = 0;
            }

        // Build graph by comparing consecutive words
        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());

            if(w1.size() > w2.size() && w1.substr(0,minLen) == w2.substr(0,minLen))
                return ""; // invalid order

            for(int j=0; j<minLen; j++){
                if(w1[j] != w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        // BFS Topological Sort
        queue<char> q;
        for(auto &[c, deg] : indegree)
            if(deg == 0) q.push(c);

        string res;
        while(!q.empty()){
            char curr = q.front(); q.pop();
            res += curr;
            for(char nei : adj[curr]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }

        return res.size() == indegree.size() ? res : ""; // check cycle
    }
};
