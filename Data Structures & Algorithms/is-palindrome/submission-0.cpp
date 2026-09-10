class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ' || !isalnum(s[i])) continue;
            char t = static_cast<char>(tolower(s[i]));
            temp+= t;
        }
        for(int i=0;i<temp.size()/2;i++){
            if(temp[i] != temp[temp.size()-i-1]) return false;
        }
        return true;
    }
};
