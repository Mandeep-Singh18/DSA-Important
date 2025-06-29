// 🍌 Problem: Koko Eating Bananas (Leetcode Hard)
// 🧠 Approach:
// 1. We want to find the minimum eating speed (bananas/hour) `m` such that Koko can finish all piles within `h` hours.
// 2. If Koko eats at speed `m`, the time to finish a pile of size `a` is ceil(a / m).
// 3. We use binary search on the answer. The lowest possible speed is 1, the highest is the max element in `piles`.
// 4. For each mid-speed `m`, we calculate total hours needed using the `hours` function.
//    - If total hours ≤ h, we try smaller speeds (move left).
//    - If total hours > h, we try bigger speeds (move right).
// 5. The smallest speed where she finishes in ≤ h hours is the answer.

long long hours(vector<int>& arr, int m){
    long long totalhour = 0;
    for(int a: arr){
        totalhour += (a + m - 1) / m; // ceil(a / m) using integer math
    }
    return totalhour; 
}

int minEatingSpeed(vector<int>& piles, int h) {
    int s = 1, e = *max_element(piles.begin(), piles.end()); // search space: [1, max pile]
    int ans = e;

    while(s <= e){
        int m = s + (e - s) / 2; // mid speed

        if(hours(piles, m) <= h){ // can finish with speed m?
            ans = m;              // try smaller speed
            e = m - 1;
        }else{
            s = m + 1;            // try larger speed
        }
    }

    return ans; // minimum speed to finish within h hours
}
