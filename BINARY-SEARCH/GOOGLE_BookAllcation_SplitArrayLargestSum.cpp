#include <vector>
#include<bits/stdc++.h>
using namespace std;

bool valid(vector<int> &nums, int k, int mid) {
    int n = nums.size();
    int stu = 1, pages = 0;                         // Initialize student count and current page sum

    for (int i = 0; i < n; i++) {
        if (nums[i] > mid) return false;            // If a single book has more pages than mid, not possible

        if (pages + nums[i] <= mid) {
            pages += nums[i];                       // Accumulate pages if within limit
        } else {
            stu++;                                  // Move to the next student
            pages = nums[i];                        // Reset pages to current book
        }
    }
    return (stu <= k);                              // Return true if students used are within limit k
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;

    if (k > n) return -1;                            // If more students than books, return -1 as impossible

    for (int i = 0; i < n; i++) {
        sum += nums[i];                              // Calculate the sum of all pages
    }

    int st = 0, end = sum, ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;              // Calculate the mid point

        if (valid(nums, k, mid)) {
            ans = mid;                              // Update answer if valid (LEFT)
            end = mid - 1;                          // Try for a smaller maximum sum 
        } else {
            st = mid + 1;                           // Otherwise, increase lower bound(RIGHT)
        }
    }
    return ans;                                     // Return the minimum maximum sum found
}   

int main(){
    vector<int> arr1 = {15,17,20};
    int k1 = 2;
    
    cout << splitArray(arr1,k1);

    return 0;
}
