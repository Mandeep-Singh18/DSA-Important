#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int target){
    int st = 0, end = arr.size() - 1;                    // Initialize start and end pointers

    while (st <= end){
        int mid = st + (end - st) / 2;                   // Calculate the mid index to avoid overflow

        if (arr[mid] == target){                         // If the middle element is the target
            return mid;                                  // Return the index
        }

        if (arr[st] <= arr[mid]){                                                                                                    // Check if the left portion is sorted
            if ((arr[st] <= target) && (arr[mid] >= target)) {    // Check if the target is within the left sorted portion
                end = mid - 1;                           // Narrow down to the left side
            }
            else{
                st = mid + 1;                            // Move to the right side
            }
        }
        else{                                                                                                                          // Right portion is sorted
            if ((arr[mid] <= target) && (arr[end] >= target)){    // Check if the target is within the right sorted portion
                st = mid + 1;                            // Narrow down to the right side
            }
            else {
                end = mid - 1;                           // Move to the left side
            }
        }
    }
    return -1;                                           // Return -1 if the target is not found
}

int main(){
    vector<int> arr1 = {4,5,6,7,0,1,2};                  // Example rotated sorted array
    int t1 = 0;                                          // Target to search in arr1

    vector<int> arr2 = {1};                              // Array with a single element
    int t2 = 0;                                          // Target to search in arr2

    cout << search(arr1, t1) << endl;                    // Output the result of search in arr1
    cout << search(arr2, t2);                            // Output the result of search in arr2

    return 0;
}
