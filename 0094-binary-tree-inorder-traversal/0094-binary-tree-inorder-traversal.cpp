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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> in;

        stack<TreeNode*> st;

        TreeNode* node = root;

        while(node != NULL || !st.empty()) {

            // Go LEFT
            while(node != NULL) {
                st.push(node);
                node = node->left;
            }

            // Take node
            node = st.top();
            st.pop();

            // Visit node
            in.push_back(node->val);

            // Go RIGHT
            node = node->right;
        }

        return in;
    }
};