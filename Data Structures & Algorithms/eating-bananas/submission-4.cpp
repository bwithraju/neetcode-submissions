class Solution {
public:
    long long calculateTime(vector<int>& piles,int k){
        long long time = 0;
        for(int i =0;i<piles.size();i++){
            time += ceil((double)piles[i]/k);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high){
            int mid = (high-low)/2 + low;
            if(calculateTime(piles,mid)<=h){
                high = mid-1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};