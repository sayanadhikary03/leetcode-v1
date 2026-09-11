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

    // ans stores the maximum sum of any BST found so far
    int ans = 0;

    // This function returns 3 values for every subtree:
    //
    // [0] -> minimum value in the subtree
    // [1] -> maximum value in the subtree
    // [2] -> sum of values in the subtree
    //
    // vector<int> is used to return all 3 values
    vector<int> solve(TreeNode* root) {

        // ----------------------------------------------------
        // STEP 1: If root is NULL, the subtree is empty.
        // ----------------------------------------------------
        //
        // For an empty tree:
        //
        // minimum = INT_MAX
        // maximum = INT_MIN
        // sum     = 0
        //
        // Why?
        // These values help the parent node pass the BST check.
        //
        if (!root) {
            return {INT_MAX, INT_MIN, 0};
        }

        // ----------------------------------------------------
        // STEP 2: First solve the LEFT subtree
        // ----------------------------------------------------
        //
        // This recursively goes all the way to the left.
        //
        // left[0] = minimum value in left subtree
        // left[1] = maximum value in left subtree
        // left[2] = sum of left subtree
        //
        vector<int> left = solve(root->left);

        // ----------------------------------------------------
        // STEP 3: Now solve the RIGHT subtree
        // ----------------------------------------------------
        //
        // right[0] = minimum value in right subtree
        // right[1] = maximum value in right subtree
        // right[2] = sum of right subtree
        //
        vector<int> right = solve(root->right);

        // ----------------------------------------------------
        // STEP 4: Check whether the current subtree is a BST
        // ----------------------------------------------------
        //
        // BST condition:
        //
        //       maximum of LEFT < root
        //
        // AND
        //
        //       root < minimum of RIGHT
        //
        // So:
        //
        // left[1] < root->val
        // root->val < right[0]
        //
        if (left[1] < root->val && root->val < right[0]) {
            // ------------------------------------------------
            // STEP 5: Current subtree IS a BST
            // ------------------------------------------------
            //
            // Calculate the total sum:
            //
            // left subtree sum
            //       +
            // current node value
            //       +
            // right subtree sum
            //
            int sum = left[2] + root->val + right[2];

            // ------------------------------------------------
            // STEP 6: Update the maximum BST sum
            // ------------------------------------------------
            //
            // If this BST has a larger sum than our previous
            // answer, update ans.
            //
            ans = max(ans, sum);
            // ------------------------------------------------
            // STEP 7: Return information about this BST
            // ------------------------------------------------
            //
            // We return:
            //
            // minimum value of current subtree
            // maximum value of current subtree
            // total sum of current subtree
            //
            return {
                min(root->val, left[0]),
                max(root->val, right[1]),
                sum
            };
        }


        // ----------------------------------------------------
        // STEP 8: Current subtree is NOT a BST
        // ----------------------------------------------------
        //
        // We return:
        //
        // INT_MIN as minimum
        // INT_MAX as maximum
        //
        // This is done deliberately.
        //
        // When the parent checks:
        //
        // left[1] < parent->val
        //
        // or
        //
        // parent->val < right[0]
        //
        // the condition will fail.
        //
        // Therefore, an invalid subtree cannot become part
        // of a larger valid BST.
        //
        return {INT_MIN, INT_MAX, 0};
    }


public:

    // --------------------------------------------------------
    // STEP 9: Main function
    // --------------------------------------------------------
    int maxSumBST(TreeNode* root) {

        // Start recursion from the root.
        //
        // solve() will visit every node and update ans.
        //
        solve(root);


        // Return the maximum sum of any BST found.
        //
        return ans;
    }
};