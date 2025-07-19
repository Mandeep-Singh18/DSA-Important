Short Approach for Twitter Class:
    This class simulates a basic Twitter system with:
    postTweet: User posts a tweet with a timestamp.
    getNewsFeed: Returns the 10 most recent tweets from the user and people they follow.
    follow/unfollow: Manages following relationships.
    Uses:
    unordered_map to store tweets (tweetMap) and follow relations (followMap).
    priority_queue (min/max-heap) to efficiently track top 10 recent tweets.


class Twitter {
public:
    int count; // Decreasing timestamp
    unordered_map<int, vector<pair<int, int>>> tweetMap; // userId -> {timestamp, tweetId}
    unordered_map<int, unordered_set<int>> followMap;    // userId -> set of followees

    Twitter() {
        count = 0; // Start from 0, decrement to simulate recent timestamps
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count, tweetId}); // Store tweet with timestamp
        if (tweetMap[userId].size() > 10)             // Keep only latest 10
            tweetMap[userId].erase(tweetMap[userId].begin());
        count--; // Decrease timestamp (most recent = smallest)
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followMap[userId].insert(userId); // User follows themselves

        // Min-heap: {timestamp, tweetId, userId, index of next tweet}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (int f : followMap[userId]) {
            if (!tweetMap.count(f)) continue;
            int idx = tweetMap[f].size() - 1;
            auto &p = tweetMap[f][idx];
            minHeap.push({p.first, p.second, f, idx - 1}); // Push latest tweet
        }

        while (!minHeap.empty() && res.size() < 10) {
            auto t = minHeap.top(); minHeap.pop();
            res.push_back(t[1]); // Add tweetId to result
            int idx = t[3];
            if (idx >= 0) {
                auto &p = tweetMap[t[2]][idx];
                minHeap.push({p.first, p.second, t[2], idx - 1}); // Push older tweet
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId); // Add followee
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)               // Can't unfollow self
            followMap[followerId].erase(followeeId);
    }
};
