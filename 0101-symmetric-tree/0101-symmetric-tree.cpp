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
    // Helper function to check if two subtrees are mirrors of each other
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // If both subtrees are empty, they are symmetric
        if (t1 == nullptr && t2 == nullptr) return true;
        
        // If only one subtree is empty, they are asymmetric
        if (t1 == nullptr || t2 == nullptr) return false;
        
        // Check if current values match, and recursively check structural mirrors
        return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right) 
            && isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};
