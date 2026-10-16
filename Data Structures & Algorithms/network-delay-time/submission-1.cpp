class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (auto& x : times) {
            edges[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        heap.push({0, k});

        set<int> visited;
        int time = 0;
        while (!heap.empty()) {
            pair<int, int> cur = heap.top();
            heap.pop();
            int cur_time = cur.first;
            int node = cur.second;

            if (visited.count(node)) {
                continue;
            }

            visited.insert(node);
            time = cur_time;

            if (edges.count(node)) {
                for (auto& x : edges[node]) {
                    int next = x.first;
                    int time_takes = x.second;
                    if (!visited.count(next)) {
                        heap.push({time_takes + time, next});
                    }
                }
            }
        }

        if (visited.size() == n) {
            return time;
        }
        return -1;
    }
};
