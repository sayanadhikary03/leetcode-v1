/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        // Store BST elements in sorted order
        vector<int> arr;
        inorder(root, arr);

        // Two pointers
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {

            int sum = arr[left] + arr[right];

            // Found the pair
            if (sum == k)
                return true;

            // Need a bigger sum
            if (sum < k)
                left++;

            // Need a smaller sum
            else
                right--;
        }

        return false;
    }

    void inorder(TreeNode* root, vector<int>& arr) {

        if (root == NULL)
            return;

        // Left
        inorder(root->left, arr);

        // Root
        arr.push_back(root->val);

        // Right
        inorder(root->right, arr);
    }
};