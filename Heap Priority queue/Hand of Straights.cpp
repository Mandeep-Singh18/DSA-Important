Count each card's frequency using a map.
Try to form consecutive groups of size groupSize starting from the smallest card.
For each group, reduce the count and erase from the map if frequency becomes 0.
If at any point a required card is missing, return false.


bool isNStraightHand(vector<int>& hand, int groupSize) {
    map<int, int> mpp;                         // Store frequency of each card

    if (hand.size() % groupSize != 0)          // If not divisible, return false
        return false;

    for (int card : hand)
        mpp[card]++;                           // Count frequency of each card

    while (!mpp.empty()) {
        int cur = mpp.begin()->first;          // Start from the smallest card

        for (int i = 0; i < groupSize; i++) {
            if (mpp[cur + i] == 0)             // If card is missing, return false
                return false;

            mpp[cur + i]--;                    // Use the card
            if (mpp[cur + i] == 0)
                mpp.erase(cur + i);            // Remove if count becomes 0
        }
    }

    return true;                               // All groups formed successfully
}
