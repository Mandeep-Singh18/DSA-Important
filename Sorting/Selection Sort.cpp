👇 Approach:
         - Find the smallest element.
         - Put it at the beginning.
         - Repeat for remaining elements.


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {                 // Loop through each element except the last one
        int minIndex = i;                         // Assume current element is the smallest
        for(int j = i+1; j < n; j++) {            // Check the rest of the array
            if(arr[j] < arr[minIndex]) {          // If a smaller element is found
                minIndex = j;                     // Update index of the smallest element
            }
        }
        swap(arr[i], arr[minIndex]);              // Swap current element with the smallest found
    }
}
