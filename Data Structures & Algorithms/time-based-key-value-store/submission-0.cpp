class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hold;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hold[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string retVal = "";
        auto& values = hold[key];
        int front = 0;
        int back = values.size() - 1;

        while (front <= back) {
            int mid = front + (back - front) / 2;

            if (values[mid].first <= timestamp) {
                retVal = values[mid].second;
                front = mid + 1;
            } else {
                back = mid - 1;
            }
        }
        return retVal;
    }
};
