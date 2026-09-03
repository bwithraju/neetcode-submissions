class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) return 0;

        int start = 0;
        int end = 0;
        int maxi = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i + 1] == nums[i]) {
                continue;
            }

            if (nums[i + 1] - nums[i] != 1) {
                maxi = max(maxi, end - start + 1);
                end = start = 0;
            }
            else {
                end++;
            }
        }

        maxi = max(maxi, end - start + 1);

        return maxi;
    }
};