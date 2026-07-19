class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> visited(26, false);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        string st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Already included
            if (visited[ch - 'a'])
                continue;

            // Remove bigger characters if they occur later
            while (!st.empty() &&
                   st.back() > ch &&
                   last[st.back() - 'a'] > i) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};