int majorityElement(vector<int>& nums) {
    // Step 1: Initialize variables
    int count = 0;  // To keep track of the frequency of the current candidate
    int ele;        // To store the current candidate for the majority element

    // Step 2: Find the candidate for majority element
    for(int i = 0; i < nums.size(); i++) {
        if(count == 0) {       // If count is zero, choose the current element as the new candidate
            count = 1;         // Reset count to 1
            ele = nums[i];     // Assign current element as the new candidate
        }
        else if(ele == nums[i]) { // If the current element is the same as the candidate
            count++;           // Increment the count
        }
        else {                 // If the current element is different from the candidate
            count--;           // Decrement the count
        }
    }

    // Step 3: Verify the candidate
    int cnt = 0;               // Variable to count the occurrences of the candidate
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == ele) {   // If the current element matches the candidate
            cnt++;             // Increment the count
        } 
    }

    // Step 4: Check if the candidate is indeed the majority element
    if(cnt > (nums.size() / 2)) { // If the count of candidate is more than half of the array size
        return ele;            // Return the candidate as the majority element
    }

    // Step 5: If no majority element found, return -1
    return -1;
}
