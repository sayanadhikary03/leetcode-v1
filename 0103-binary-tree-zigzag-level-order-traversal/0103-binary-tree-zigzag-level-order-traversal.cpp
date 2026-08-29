/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) return result;

        queue<TreeNode*> nodequeue;
        nodequeue.push(root);

        bool lefttoright = true;

        while (!nodequeue.empty()) {
            int n = nodequeue.size();

            vector<int> list(n);

            for (int i = 0; i < n; i++) {
                TreeNode* node = nodequeue.front();
                nodequeue.pop();

                // Position where we put the node value
                int index = lefttoright ? i : (n - 1 - i);

                list[index] = node->val;

                if (node->left != NULL)
                    nodequeue.push(node->left);

                if (node->right != NULL)
                    nodequeue.push(node->right);
            }  // <-- CLOSE THE FOR LOOP HERE

            // Switch direction for the next level
            lefttoright = !lefttoright;

            // Add current level
            result.push_back(list);
        }

        return result;
    }
};