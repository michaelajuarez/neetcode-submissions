class Solution {
public:
    unordered_map<int, vector<int>> hold;
    unordered_set<int> check;

    bool dfs(int cur) {
        if (check.contains(cur)) {
            return false;
        }

        if (hold[cur].empty()) return true;

        check.insert(cur);
        for (auto x : hold[cur]) {
            if (!dfs(x)) return false;
        }
        check.erase(cur);
        hold[cur].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            hold[i] = {};
        }
        for (auto x : prerequisites) {
            hold[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
