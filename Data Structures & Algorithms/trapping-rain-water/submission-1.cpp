class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;

        while (i < j && height[i] < height[i + 1]) {
            i++;
        }

        while (i < j && height[j - 1] > height[j]) {
            j--;
        }

        stack<int> st;
        queue<int> q;

    
        for (int k = i; k <= j; k++) {
            st.push(st.empty() ? height[k] : max(height[k], st.top()));
        }

      
        int rightMax = 0;
        for (int k = j; k >= i; k--) {
            rightMax = max(rightMax, height[k]);
            q.push(rightMax);
        }

        int totalBlocks = 0;

        for (int k = i; k <= j; k++) {
            int leftMax = st.top();
            st.pop();

            int rightMax = q.front();
            q.pop();

            totalBlocks += min(leftMax, rightMax);
        }

        int notWater = 0;

        for (int k = i; k <= j; k++) {
            notWater += height[k];
        }

        return totalBlocks - notWater;
    }
};