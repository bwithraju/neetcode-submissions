class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int result = 0;
        while(i<j){
            result  = max(result,(j-i)*min(heights[i],heights[j]));
            (heights[i]<heights[j])?i++:j--;
        }
        return result;
    }

};
