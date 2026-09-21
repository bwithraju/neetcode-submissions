class TimeMap {
public:
    map<string,vector<pair<string,int>>> mapT;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mapT[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int start = 0;
        int end = mapT[key].size()-1;
        int timestamp_prev = -1; 
        while(start<=end){
            int mid = (end-start)/2 + start;
            if(mapT[key][mid].second<=timestamp){
                timestamp_prev = mid;
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return (timestamp_prev==-1)?"":mapT[key][timestamp_prev].first;
    }
};
