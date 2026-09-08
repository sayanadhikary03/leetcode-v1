class Solution {
public:
    // Morris Preorder Traversal
    // Time: O(n) | Space: O(1)

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // No left subtree → visit curr
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor
                // = rightmost node in left subtree
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }
                if (IP->right == NULL) {
                    // First time at curr → visit curr BEFORE going left
                    ans.push_back(curr->val);
                    // Create temporary thread to come back to curr
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    // Coming back through the thread
                    // Remove the temporary link
                    IP->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};