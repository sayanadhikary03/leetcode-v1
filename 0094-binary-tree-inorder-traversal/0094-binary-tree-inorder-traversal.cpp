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
    // -----------------Morris Inorder Traversal
    // ------------------------------------------Time: O(n) | Space: O(1)

    // No left → visit → go right

    // Has left → find predecessor
    //      → create thread → go left

    // Come back through thread
    //      → remove thread → visit → go right


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // No left subtree → visit current node
                ans.push_back(curr->val);
                // Move to right subtree
                curr = curr->right;
            }
            else {
                // Find inorder predecessor:
                // rightmost node in the left subtree
                // Example: for 5, its predecessor may be 4
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    // First time reaching curr:
                    // create a temporary link back to curr
                    IP->right = curr;
                    // Go to the left subtree
                    curr = curr->left;
                }
                else {
                    // Left subtree is already processed:
                    // remove the temporary link
                    IP->right = NULL;
                    // Now visit curr
                    ans.push_back(curr->val);
                    // Move to the right subtree
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};