class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<int>v;
        for(auto &p:m){
            v.push_back(p.second);
        }
        sort(v.rbegin(),v.rend());
        int t=v[k-1];
        vector<int>n;
        for(auto &p:m)
        {
            if(p.second>=t)
            {
                n.push_back(p.first);
            }
        }return n;

    }
};
