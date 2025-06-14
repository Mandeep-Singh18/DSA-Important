👇 Approach:
    -  Take one element at a time. 
    -  Insert it at the correct position in the sorted part.


void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {                 // Start from second element
        int key = arr[i];                        // Current element to insert
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {          // Shift elements greater than key to the right
            arr[j+1] = arr[j];                   // Move element one step ahead
            j--;
        }
        arr[j+1] = key;                          // Insert key at the correct position
    }
}
