Count frequency of each task (A-Z).
Use a max-heap to always schedule the task with the highest remaining count.
Use a queue to track tasks during their cooldown period (n units).
At each time unit:
Execute a task from heap (if available).
Put it into cooldown if it still has remaining count.
Re-add tasks from cooldown if their wait is over.
Repeat until both heap and cooldown queue are empty.


int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);                // Count frequency of each task
    for (char task : tasks)
        count[task - 'A']++;

    priority_queue<int> maxHeap;             // Max-heap for most frequent tasks
    for (int cnt : count)
        if (cnt > 0) maxHeap.push(cnt);

    int time = 0;
    queue<pair<int, int>> q;                 // {remaining_count, available_time}

    while (!maxHeap.empty() || !q.empty()) {
        time++;

        if (!maxHeap.empty()) {
            int cnt = maxHeap.top() - 1;     // Execute most frequent task
            maxHeap.pop();
            if (cnt > 0)
                q.push({cnt, time + n});     // Add to cooldown queue
        }

        if (!q.empty() && q.front().second == time) {
            maxHeap.push(q.front().first);   // Task cooldown complete, reinsert
            q.pop();
        }
    }

    return time;                             // Total time to finish all tasks
}
