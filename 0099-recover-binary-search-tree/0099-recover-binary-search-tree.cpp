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
private:
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
            
        // Visit left subtree
        inorder(root->left);

        // Check if BST property is violated
        if (prev != NULL && root->val < prev->val) {
            // First violation
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            // Second violation
            else {
                last = root;
            }
        }
        // Current node becomes previous node
        prev = root;
        // Visit right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Find the two misplaced nodes
        inorder(root);

        // Non-adjacent nodes were swapped
        if (first != NULL && last != NULL) {
            swap(first->val, last->val);
        }
        // Adjacent nodes were swapped
        else if (first != NULL && middle != NULL) {
            swap(first->val, middle->val);
        }
    }
};