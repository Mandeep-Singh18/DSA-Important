👇 Approach:
        - Divide the array into two halves.       
        - Sort each half recursively       
        - Merge the sorted halves.


void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;                            // Temporary array to store merged result
    int i = low, j = mid+1;

    while(i <= mid && j <= high) {               // Compare elements from both halves
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);  // If left is smaller, add to temp
        else temp.push_back(arr[j++]);                  // If right is smaller, add to temp
    }

    while(i <= mid) temp.push_back(arr[i++]);    // Copy remaining elements from left half
    while(j <= high) temp.push_back(arr[j++]);   // Copy remaining elements from right half

    for(int k = low; k <= high; k++)             // Copy back sorted elements to original array
        arr[k] = temp[k - low];
}

void mergeSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;                      // Base case: one element is already sorted
    int mid = (low + high) / 2;                  // Find middle index
    mergeSort(arr, low, mid);                    // Sort left half
    mergeSort(arr, mid+1, high);                 // Sort right half
    merge(arr, low, mid, high);                  // Merge both sorted halves
}
