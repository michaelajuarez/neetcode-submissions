class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto x : nums) {
            heap.push(x);
            if (heap.size() > k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > k) {
            heap.pop();
        }
        return heap.top();
    }
};
