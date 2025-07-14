    Each car has a position and speed.
    The time it takes to reach the destination is:
    time = (target - position) / speed.
    Sort cars by position in descending order (cars closer to the target come first).
    Iterate from closest to farthest:
    Push each car’s time to reach the target onto a stack.
    If a car catches up with the one ahead (i.e., reaches in less or equal time), it merges into the same fleet, so pop it.
    The number of fleets will be the size of the stack.


int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> pair;  // Store {position, speed}

    for (int i = 0; i < position.size(); i++) {
        pair.push_back({position[i], speed[i]});  // Build pair list
    }

    sort(pair.rbegin(), pair.rend());  // Sort by position descending

    vector<double> stack;  // Stack to hold times to reach target

    for (auto& p : pair) {
        // Calculate time to reach target
        stack.push_back((double)(target - p.first) / p.second);

        // If this car catches up to fleet ahead, merge (pop current)
        if (stack.size() >= 2 && 
            stack.back() <= stack[stack.size() - 2]) {
            stack.pop_back();  // Merge into same fleet
        }
    }

    return stack.size();  // Number of fleets
}
