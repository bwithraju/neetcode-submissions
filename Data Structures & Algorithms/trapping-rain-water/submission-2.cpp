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

      
        for (int k = j; k >= i; k--) {
            q.push(q.empty() ? height[k] : max(height[k], q.back()));
        }

        int totalBlocks = 0;

        for (int k = i; k <= j; k++) {
            totalBlocks += min(st.top(), q.front());
            st.pop();
            q.pop();
        }

        int notWater = 0;

        for (int k = i; k <= j; k++) {
            notWater += height[k];
        }

        return totalBlocks - notWater;
    }
};