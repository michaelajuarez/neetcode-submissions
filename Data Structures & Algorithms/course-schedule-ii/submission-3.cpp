class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> q;
        vector<int> retArr;

        for (auto& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            degree[x[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            retArr.push_back(front);
            for (auto& x : adj[front]) {
                degree[x]--;
                if (degree[x] == 0) {
                    q.push(x);
                }
            }
        }

        if (retArr.size() < numCourses) return {};
        return retArr;
    }
};
