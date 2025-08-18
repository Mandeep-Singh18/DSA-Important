Short Approach
      First check if total gas < total cost → return -1 (impossible).
      Otherwise, there must be a valid starting point.
      Traverse stations:
      Keep a running total (net gas left).
      If it becomes negative, it means the journey can’t start from the current segment, so reset total = 0 and move the start point to i+1.
      At the end, return the valid starting index.


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gassum = accumulate(gas.begin(), gas.end(), 0);   // total gas
    int costsum = accumulate(cost.begin(), cost.end(), 0); // total cost

    if (gassum < costsum) return -1;  // impossible if cost > gas

    int total = 0, ans = 0;
    for (int i = 0; i < gas.size(); i++) {
        total += gas[i] - cost[i];    // net gain/loss at station i
        if (total < 0) {              // can't reach next station
            total = 0;                // reset balance
            ans = i + 1;              // next station is new start
        }
    }
    return ans;                       // valid starting index
}
