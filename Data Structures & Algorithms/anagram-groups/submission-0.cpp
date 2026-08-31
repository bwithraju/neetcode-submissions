class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy = strs;
        for(int i=0;i<copy.size();i++){
            sort(copy[i].begin(),copy[i].end());
        }
        map <string,vector<string>> freq;
        for(int i=0;i<copy.size();i++){
            freq[copy[i]].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto &p : freq){
            result.push_back(p.second);
        }
        return result;

    }
};
