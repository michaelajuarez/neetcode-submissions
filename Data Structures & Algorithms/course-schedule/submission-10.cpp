class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> hold;

        for (auto& x : prerequisites) {
            inDeg[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                hold.push(i);
            }
        }

        int count = 0;
        while (!hold.empty()) {
            int front = hold.front();
            hold.pop();
            count++;
            for (int x : adj[front]) {
                inDeg[x]--;
                if (inDeg[x] == 0) {
                    hold.push(x);
                }
            }
        }
        
        return count == numCourses;
    }
};
