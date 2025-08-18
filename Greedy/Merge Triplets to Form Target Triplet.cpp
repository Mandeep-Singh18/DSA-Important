Short Approach
      Ignore any triplet that has a value greater than the corresponding target element (can’t be part of target).
      For valid triplets, check if they match any of the target’s values.
      If t[i] == target[i], mark that index as "covered".
      If all 3 indices (0,1,2) are covered, return true.
      Else return false.


bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    unordered_set<int> good;                           // store matched indices

    for (const auto& t : triplets) {
        if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) 
            continue;                                  // skip invalid triplet

        for (int i = 0; i < 3; i++) {                  // check each position
            if (t[i] == target[i]) 
                good.insert(i);                        // mark as covered
        }
    }
    return good.size() == 3;                           // all indices matched?
}
