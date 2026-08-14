class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {end time, start time}
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({intervals[i][1], intervals[i][0]});
        }

        // Sort by ending time
        sort(meetings.begin(), meetings.end());

        int count = 1;
        int freeTime = meetings[0].first;

        for (int i = 1; i < n; i++) {

            int startTime = meetings[i].second;
            int endTime = meetings[i].first;

            if (startTime >= freeTime) {
                count++;
                freeTime = endTime;
            }
        }

        return n - count;
    }
};