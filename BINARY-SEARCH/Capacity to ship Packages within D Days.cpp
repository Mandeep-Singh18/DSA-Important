bool isdays(vector<int>& weights, int mid, int days){
    int curdays = 1, load = 0;
    for(int w: weights){
        if(load + w > mid){     // too much for today
            curdays++;          // need one more day
            load = w;           // start new day
        }else{
            load += w;          // add to current day's load
        }
    }
    return curdays <= days;     // return true if we used allowed days or less
}

int shipWithinDays(vector<int>& weights, int days) {
    int s = *max_element(weights.begin(), weights.end());         // minimum capacity (must carry heaviest)
    int e = accumulate(weights.begin(), weights.end(), 0);        // maximum capacity (carry all in 1 day)
    int ans = e;

    while(s <= e){
        int m = s + (e - s) / 2;       // guess a capacity

        if(isdays(weights, m, days)){ // can we ship in time?
            ans = m;                  // yes, save as answer
            e = m - 1;                // try smaller capacity
        }else{
            s = m + 1;                // need more capacity
        }
    }
    return ans; // smallest capacity to ship within given days
}
