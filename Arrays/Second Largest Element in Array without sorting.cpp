**FOR SECOND LARGEST**

int secondLargest(int arr[], int n) {
        // If the array has less than 2 elements, return -1
        if (n < 2) 
            return -1;
    
        // Initialize the largest and second largest as INT_MIN
        int large = INT_MIN, second_large = INT_MIN;
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // If the current element is greater than the largest, update second largest and largest
            if (arr[i] > large) {
                second_large = large;
                large = arr[i];
            }
            // If current element is less than largest but greater than second largest
            else if (arr[i] > second_large && arr[i] != large) {
                second_large = arr[i];
            }
        }
        
        // If second_large was not updated, return -1 (no second largest element exists)
        return (second_large == INT_MIN) ? -1 : second_large;
    }



**FOR SECOND SMALLEST**
  
int secondSmallest(int arr[], int n) {
    // If the array has fewer than 2 elements, return -1
    if (n < 2) {
        return -1;
    }

    // Initialize variables to store the smallest and second smallest elements
    int smallest = INT_MAX, second_smallest = INT_MAX;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If the current element is smaller than the smallest element
        if (arr[i] < smallest) {
            second_smallest = smallest;  // Update second smallest
            smallest = arr[i];           // Update smallest
        }
        // If current element is greater than smallest but less than second smallest
        else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];  // Update second smallest
        }
    }

    // If second_smallest was not updated, return -1 (indicating no second smallest element)
    return (second_smallest == INT_MAX) ? -1 : second_smallest;
}
