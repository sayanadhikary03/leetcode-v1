/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        // If tree is empty, width is 0
        if (!root)
            return 0;

        // Store maximum width found so far
        int ans = 0;

        // Queue stores:
        // {node, virtual index of node}
        //
        // long long is used to prevent integer overflow
        queue<pair<TreeNode*, long long>> q;

        // Root starts at virtual index 0
        q.push({root, 0});

        while (!q.empty()) {

            // Number of nodes in the current level
            int size = q.size();

            // Smallest index of the current level
            // We use it to normalize the indices
            long long mini = q.front().second;

            // Index of first and last node in this level
            long long first = 0;
            long long last = 0;

            // Process all nodes of the current level
            for (int i = 0; i < size; i++) {

                // Normalize the current index
                // This keeps the numbers small
                long long cur_id = q.front().second - mini;

                // Get the current node
                TreeNode* node = q.front().first;

                // Remove current node from queue
                q.pop();

                // First node of this level
                if (i == 0)
                    first = cur_id;

                // Last node of this level
                if (i == size - 1)
                    last = cur_id;

                // Left child gets index:
                // 2 * parent_index + 1
                if (node->left)
                    q.push({
                        node->left,
                        cur_id * 2 + 1
                    });

                // Right child gets index:
                // 2 * parent_index + 2
                if (node->right)
                    q.push({
                        node->right,
                        cur_id * 2 + 2
                    });
            }

            // Width of current level
            // +1 because both first and last positions are included
            ans = max(ans, (int)(last - first + 1));
        }

        // Return maximum width of the tree
        return ans;
    }
};