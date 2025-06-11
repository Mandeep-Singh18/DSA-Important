## Approach

-Use three pointers:
  
  low → for 0s  
  mid → for current element  
  high → for 2s
  
-Traverse the array:
  
  If nums[mid] == 0, swap with low and move both low and mid.  
  If nums[mid] == 1, just move mid.  
  If nums[mid] == 2, swap with high and move high only.

## code

  void sortColors(vector<int>& nums) {
    int low = 0;              // Pointer for 0s
    int mid = 0;              // Pointer for current element
    int high = nums.size()-1; // Pointer for 2s

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]); // Swap 0 to the front
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;                      // Move on if 1
        }
        else{
            swap(nums[mid], nums[high]); // Swap 2 to the end
            high--;
        }
    }
  }
