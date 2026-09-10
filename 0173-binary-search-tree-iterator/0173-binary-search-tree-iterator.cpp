
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

class BSTIterator {

private:
    stack<TreeNode*> myStack;

    // Push all the left nodes into the stack
    void pushAll(TreeNode* root) {
        for (; root != NULL; root = root->left) {
            myStack.push(root);
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    // Return the next smallest value
    int next() {
        // Get the top node
        TreeNode* myTemp = myStack.top();
        // Remove it from stack
        myStack.pop();
        // Process the right subtree
        pushAll(myTemp->right);
        // Return the value
        return myTemp->val;
    }

    // Check if more nodes are available
    bool hasNext() {
        return !myStack.empty();
    }
};
