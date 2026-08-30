class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int retVar = right;
        
        while (left <= right) {
            int mid = (left + right) / 2;

            long long time = 0;
            for (auto x : piles) {
                time += ceil(static_cast<double>(x) / mid);
            }
            
            if (time <= h) {
                retVar = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return retVar;
    }
};
