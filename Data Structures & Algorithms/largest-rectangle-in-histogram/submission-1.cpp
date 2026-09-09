class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int ans =0;
        int n = heights.size();
        vector<int> right(n,0);
        stack<int> s1;
        for(int i = n-1 ;i>=0;i--){
            while(s1.size()>0 && heights[s1.top()] >= heights[i]){
                s1.pop();
            }
            right[i] = s1.empty()?n:s1.top();
            s1.push(i);
        }
        vector<int> left(n,0);
        stack<int> s2;
        for(int i = 0 ;i<n;i++){
            while(s2.size()>0 && heights[s2.top()] > heights[i]){
                s2.pop();
            }
            left[i] = s2.empty()?-1:s2.top();
            s2.push(i);
        }
        for(int i=0;i<n;i++){
            int currAns = heights[i]*(right[i]-left[i]-1);
            ans = max(currAns,ans);
        }
        return ans;
    }
};