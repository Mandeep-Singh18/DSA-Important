Short Approach
    If total cards are not divisible by groupSize → return false.
    Count frequency of each card using a hash map.
    Sort the hand (so we always start with the smallest available card).
    For each card in sorted order:
    If its count > 0, try to form a consecutive group of size groupSize.
    If any card in that range is missing → return false.
    Otherwise, reduce counts for those cards.
    If all groups are successfully formed → return true.
  
Time: O(n log n) (sorting dominates; each card processed once)
Space: O(n) (hash map for counts)

  

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;  // must divide evenly

    unordered_map<int, int> count;  
    for (int num : hand) count[num]++;               // count frequency

    sort(hand.begin(), hand.end());                  // sort for smallest start
    for (int num : hand) {
        if (count[num] > 0) {                        // if card still available
            for (int i = num; i < num + groupSize; i++) {
                if (count[i] == 0) return false;     // missing card
                count[i]--;                          // use this card
            }
        }
    }
    return true;                                     // successfully grouped
}



