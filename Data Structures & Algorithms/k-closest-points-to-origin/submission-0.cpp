class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> retArr;
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<>> heap;
        
        for (auto x : points) {
            double res = sqrt(pow(x[0], 2) + pow(x[1], 2));
            heap.push({res, x});
        }
        
        for (int i = 0; i < k; i++) {
            retArr.push_back(heap.top().second);
            heap.pop();
        }
        return retArr;
    }
};
