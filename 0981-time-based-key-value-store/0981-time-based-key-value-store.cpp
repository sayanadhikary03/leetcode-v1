class TimeMap {
public:
    // key -> [(timestamp, value), (timestamp, value), ...]
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    // Store the value with its timestamp
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    // Return the latest value whose timestamp <= given timestamp
    string get(string key, int timestamp) {

        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int, string>> &v = mp[key];

        int low = 0;
        int high = v.size() - 1;

        string ans = "";

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Found a valid timestamp
            if (v[mid].first <= timestamp) {

                ans = v[mid].second; // Save current answer

                // Try to find a larger valid timestamp
                low = mid + 1;
            }
            else {

                // Timestamp is too large
                high = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */