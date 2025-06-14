👇 Approach (Easy Language):
          - Compare adjacent elements.        
          - Swap them if they're in the wrong order.         
          - Repeat until the array is sorted.


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {                    // Run n-1 passes
        for(int j = 0; j < n-i-1; j++) {              // Compare each pair in unsorted part
            if(arr[j] > arr[j+1]) {                   // If current element is bigger than next
                swap(arr[j], arr[j+1]);               // Swap them to push larger one right
            }
        }
    }
}
