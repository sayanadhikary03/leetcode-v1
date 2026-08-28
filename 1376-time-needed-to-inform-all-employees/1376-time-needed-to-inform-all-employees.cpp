class Solution {
public:

    int dfs(int employee, vector<vector<int>>& tree, vector<int>& informTime) {
        int maxTime = 0;

        for (int child : tree[employee]) {
            maxTime = max(maxTime, dfs(child, tree, informTime));
        }

        return informTime[employee] + maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {

        vector<vector<int>> tree(n);

        // Build tree
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i);
            }
        }

        return dfs(headID, tree, informTime);
    }
};