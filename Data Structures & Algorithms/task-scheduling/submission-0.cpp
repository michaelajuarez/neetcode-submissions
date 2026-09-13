class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqs;
        priority_queue<int> heap;

        for (auto x : tasks) {
            if (!freqs.contains(x)) {
                freqs[x] = 1;
            } else {
                freqs[x]++;
            }
        }

        for (auto [k, v] : freqs) {
            heap.push(v);
        }

        int time = 0;
        queue<pair<int, int>> q;

        while (!heap.empty() or !q.empty()) {
            time++;

            if (heap.empty()) {
                time = q.front().second;
            } else {
                int cur = heap.top() - 1;
                heap.pop();
                if (cur > 0) {
                    q.push({cur, time + n});
                }
            }

            if (!q.empty() and q.front().second == time) {
                heap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
