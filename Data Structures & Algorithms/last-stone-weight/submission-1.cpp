class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (auto x : stones) {
            heap.push(x);
        }
        while (heap.size() > 1) {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            if (first < second) {
                second = second - first;
                heap.push(second);
            } else if (second < first) {
                first = first - second;
                heap.push(first);
            }
        }
        if (heap.size() > 0) {
            return heap.top();
        }
        return 0;
    }
};
