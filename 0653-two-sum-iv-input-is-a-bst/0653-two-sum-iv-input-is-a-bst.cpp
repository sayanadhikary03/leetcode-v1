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
    stack<TreeNode*> myStack;

    // false -> normal inorder:  smallest to largest
    // true  -> reverse inorder: largest to smallest
    bool reverse;

public:

    // Constructor
    BSTIterator(TreeNode* root, bool isReverse) {

        reverse = isReverse;

        // Put the initial path into the stack
        pushAll(root);
    }

    // Returns true if there are still nodes left
    bool hasNext() {
        return !myStack.empty();
    }

    // Returns the next element
    int next() {

        // Get the top node from the stack
        TreeNode* tmpNode = myStack.top();
        myStack.pop();

        // If normal inorder:
        // after visiting a node, go to its right subtree
        if (!reverse)
            pushAll(tmpNode->right);

        // If reverse inorder:
        // after visiting a node, go to its left subtree
        else
            pushAll(tmpNode->left);

        return tmpNode->val;
    }

private:

    // Push nodes along one side of the tree
    void pushAll(TreeNode* node) {

        while (node != NULL) {

            myStack.push(node);

            if (reverse) {

                // Reverse inorder:
                // Right -> Root -> Left
                // So go as far right as possible
                node = node->right;

            } else {

                // Normal inorder:
                // Left -> Root -> Right
                // So go as far left as possible
                node = node->left;
            }
        }
    }
};


class Solution {
public:

    bool findTarget(TreeNode* root, int k) {

        // Empty tree cannot contain two elements
        if (!root)
            return false;

        // Iterator 1:
        // Gives elements from smallest to largest
        BSTIterator l(root, false);

        // Iterator 2:
        // Gives elements from largest to smallest
        BSTIterator r(root, true);

        // Start with the smallest element
        int i = l.next();

        // Start with the largest element
        int j = r.next();

        // Continue until the two pointers meet/cross
        while (i < j) {

            // Found two elements whose sum is k
            if (i + j == k)
                return true;

            // Sum is too small:
            // Need a bigger number
            else if (i + j < k)
                i = l.next();

            // Sum is too large:
            // Need a smaller number
            else
                j = r.next();
        }

        // No pair found
        return false;
    }
};