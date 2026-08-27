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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>list;
        st.push(root);
        if (root == NULL) return {};

        while(!st.empty()){
            auto it = st.top();
            st.pop();
        
            list.push_back(it->val);

            if(it->left != NULL) st.push(it->left);
            if(it->right != NULL) st.push(it->right);
        }
        reverse(list.begin(), list.end());

        return list;

    }
};