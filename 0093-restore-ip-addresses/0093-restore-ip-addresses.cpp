class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int idx, int part, string curr) {

        // All 4 parts are formed
        if (part == 4) {
            if (idx == s.size()) {
                curr.pop_back();          // Remove last '.'
                ans.push_back(curr);
            }
            return;
        }

        int num = 0;

        // Try taking 1, 2 or 3 digits
        for (int i = idx; i < min(idx + 3, (int)s.size()); i++) {

            num = num * 10 + (s[i] - '0');

            if (num > 255)
                break;

            backtrack(s, i + 1, part + 1,
                      curr + to_string(num) + ".");

            // Leading zero check
            if (num == 0)
                break;
        }
    }

    vector<string> restoreIpAddresses(string s) {

        if (s.size() < 4 || s.size() > 12)
            return {};

        backtrack(s, 0, 0, "");

        return ans;
    }
};