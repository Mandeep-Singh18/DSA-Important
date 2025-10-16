🧠 Short Approach
    Model flights as a graph (src -> destinations).
    Sort destinations in lexicographical order (reverse for efficient pop).
    Use stack-based DFS (Hierholzer’s algorithm) to build Eulerian path.
    Reverse the result to get correct itinerary.

⏱️ Time & Space Complexity
    Time: O(E log E) → sorting destinations and visiting edges.
    Space: O(E + V) → adjacency list + stack + result.

💡 In short:
    DFS through graph edges (lexical order) → construct itinerary covering all tickets exactly once.

💻 Code (With Short Comments)
  
vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> adj;

    for(const auto& ticket : tickets)
        adj[ticket[0]].push_back(ticket[1]);   // build graph

    for(auto& [src, destinations] : adj)
        sort(destinations.rbegin(), destinations.rend()); // reverse sort

    vector<string> res;
    stack<string> stk;
    stk.push("JFK"); // start point

    while(!stk.empty()){
        string curr = stk.top();
        if(adj[curr].empty()){            // no further destinations
            res.push_back(curr);           // add to itinerary
            stk.pop();
        } else {
            string next = adj[curr].back(); 
            adj[curr].pop_back();          // remove edge
            stk.push(next);                // move to next
        }
    }

    reverse(res.begin(), res.end());       // reverse for correct order
    return res;
}
