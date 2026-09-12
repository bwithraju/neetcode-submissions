class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rs = 0;
       int re = matrix.size()-1;
       int rr = 0;
       while(rs<=re){
        int mid = (re-rs)/2 + rs;
        if(target < matrix[mid][0]){
            re = mid - 1;
        }
        else if(target > matrix[mid][0]){
            if (mid == matrix.size() - 1 || target < matrix[mid + 1][0]) {
                rr = mid;
                break;
            }else{
                rs = mid + 1;
                }
            }
            else{
                return true;
            }
        }
       int cs = 0;
       int ce = matrix[rr].size()-1;
       while(cs<=ce){
        int mid = (ce-cs)/2 + cs;
        if(target < matrix[rr][mid]){
            ce = mid - 1;
        }
        else if(target > matrix[rr][mid]){
            cs = mid + 1;
        }
        else{
            return true;
        }
       }
       return false;

    }
};
