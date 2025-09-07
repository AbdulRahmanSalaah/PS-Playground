class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty())
            return 0;
        if (n == 0)
            return tasks.size(); // no cooling needed

        vector<int> freq(26, 0);
        for (auto c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> pq;
        for (auto it : freq) {
            if (it > 0) {
                pq.push(it);
            }
        }

        // cooling queue: pair<remaining_count, time_to_enter_again>
        queue<pair<int, int>> q;

        int time = 0;

        while (!q.empty() || !pq.empty()) {
            time++;

            if (pq.empty()) {
                time = q.front().second;
            } else {
                int cnt = pq.top();
                cnt--;
                pq.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};