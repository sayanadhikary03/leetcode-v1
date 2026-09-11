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
    int ans = 0;
    // {minValue, maxValue, sum}
    vector<int> solve(TreeNode* root) {
        // Empty tree is a valid BST
        // min = +INF, max = -INF, sum = 0
        if (!root) {
            return {INT_MAX, INT_MIN, 0};
        }

        // Get information from left and right subtree
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        // Check if current tree is a valid BST
        if (left[1] < root->val && root->val < right[0]) {
            int sum = left[2] + right[2] + root->val;
            // Update maximum BST sum
            ans = max(ans, sum);
            // Return information about this BST
            return {
                min(root->val, left[0]),
                max(root->val, right[1]),
                sum
            };
        }
        // Invalid BST
        // Return values that will make the parent fail
        return {INT_MIN, INT_MAX, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};