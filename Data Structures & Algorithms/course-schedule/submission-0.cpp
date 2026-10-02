class Solution {
public:
    unordered_map<int, vector<int>> pre;
    unordered_set<int> visit;

    bool dfs(int course) {
        if (visit.count(course)) {
            return false;
        }
        
        if (pre[course].empty()) {
            return true;
        }

        visit.insert(course);
        for (int x : pre[course]) {
            if (!dfs(x)) {
                return false;
            }
        }
        visit.erase(course);
        pre[course].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            pre[i] = {};
        }
        for (auto x : prerequisites) {
            pre[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
