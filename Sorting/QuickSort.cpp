👇 Approach:
         - Pick a pivot.          
         - Put all smaller on the left, greater on the right.          
         - Sort left and right parts recursively.


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];                // Choose the last element as pivot
    int i = low - 1;                      // Index of smaller element

    for(int j = low; j < high; j++) {     // Traverse the array
        if(arr[j] < pivot) {              // If current element is smaller than pivot
            i++;                          // Move the smaller element index forward
            swap(arr[i], arr[j]);         // Swap current element with the element at i
        }
    }

    swap(arr[i+1], arr[high]);            // Place pivot at its correct position
    return i + 1;                         // Return pivot index
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {                          // Continue if there are at least 2 elements
        int pi = partition(arr, low, high);   // Partition the array, get pivot index
        quickSort(arr, low, pi - 1);          // Recursively sort left part
        quickSort(arr, pi + 1, high);         // Recursively sort right part
    }
}
