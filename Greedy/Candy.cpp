Short Approach
      Each child must get at least 1 candy → initialize two arrays L2R and R2L with 1.
      Left → Right pass:
      If ratings[i] > ratings[i-1], then L2R[i] = L2R[i-1] + 1.
      Ensures increasing ratings from left get more candies.
      Right → Left pass:
      If ratings[i] > ratings[i+1], then R2L[i] = R2L[i+1] + 1.
      Ensures increasing ratings from right get more candies.
      Final candies for each child = max(L2R[i], R2L[i]).
      Take maximum because a child must satisfy both neighbors.
      Sum up the result.


  
🔹 Code with Short Comments
int candy(vector<int>& ratings) {
    int n = ratings.size();

    vector<int> L2R(n, 1), R2L(n, 1);          // Step 1: init with 1

    for (int i = 1; i < n; i++)                // Step 2: left → right
        if (ratings[i] > ratings[i - 1]) 
            L2R[i] = L2R[i - 1] + 1;

    for (int i = n - 2; i >= 0; i--)           // Step 3: right → left
        if (ratings[i] > ratings[i + 1]) 
            R2L[i] = R2L[i + 1] + 1;

    int totalCandies = 0;                      
    for (int i = 0; i < n; i++)                // Step 4: take max at each index
        totalCandies += max(L2R[i], R2L[i]);

    return totalCandies;                       // Step 5: return sum
}
