class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0;
        heights.push_back(0);
        int n = heights.size();

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(maxArea, h * w);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }
};