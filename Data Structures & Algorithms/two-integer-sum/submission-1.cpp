class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n=nums.size();
      unordered_map<int,int> m;
      for(int i=0;i<n;i++) {
       int x=nums[i];
       int targ=target-x;
       if(m.find(targ)!=m.end()) {
        return {m[targ],i};
       }
       m[x]=i;
      }  
    }
};
