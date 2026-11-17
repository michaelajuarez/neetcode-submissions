class Solution {
public:
    int maxArea(vector<int>& heights) {
        int front = 0;
        int back = heights.size() - 1;
        int retVar = INT_MIN;

        while (front < back) {
            int cur = min(heights[back], heights[front]) * (back - front);
            retVar = max(retVar, cur);
            if (heights[front] < heights[back]) {
                front++;
            } else {
                back--;
            }
        }

        return retVar;
    }
};
