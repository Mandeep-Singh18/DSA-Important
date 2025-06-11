int maxProfit(vector<int>& prices) {

    int maxprofit = 0;             // To store the maximum profit
    int minimum = INT_MAX;         // To track the minimum price seen so far

    for(int i = 0; i < prices.size(); i++){
        minimum = min(minimum, prices[i]);                    // Update minimum price if current is lower
        maxprofit = max(maxprofit, (prices[i] - minimum));    // Calculate profit and update maxprofit if it's higher
    }

    return maxprofit;               // Return the maximum profit
}
