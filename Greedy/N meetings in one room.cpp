Short Approach
      Pair each meeting with (start, end, position).
      Sort meetings by end time (if tie, by position).
      Always pick the meeting that finishes earliest → greedy choice.
      Keep track of the last meeting’s end time (limit).
      Select the next meeting only if its start > limit.
      Store the positions of selected meetings as the answer.

🔹 Complexity
      Sorting: O(n log n)
      Loop selection: O(n)
      Total: O(n log n)
  

🔹 Code with Short Comments
struct meeting {
    int start;
    int end;
    int pos;
};

class Solution {
public:
    // custom comparator: sort by end time, then by position
    static bool comparator(struct meeting m1, struct meeting m2) {
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        else return m1.pos < m2.pos;
    }

    void maxMeetings(int s[], int e[], int n) {
        meeting meet[n];
        for (int i = 0; i < n; i++) 
            meet[i] = {s[i], e[i], i + 1}; // store start, end, position

        sort(meet, meet + n, comparator);  // sort by end time

        vector<int> answer;
        int limit = meet[0].end;           // first meeting chosen
        answer.push_back(meet[0].pos);

        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {   // if next meeting starts after last end
                limit = meet[i].end;       // update end time
                answer.push_back(meet[i].pos);
            }
        }

        cout << "The order in which the meetings will be performed is\n";
        for (int id : answer) cout << id << " ";
    }
};



Space: O(n) for storing meetings
