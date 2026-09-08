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
    // Stores the previously processed node.
    // Since we process in Reverse Preorder (Right -> Left -> Root),
    // this helps us connect the current node to the next node
    // in the flattened linked list.
    TreeNode* nextRight = NULL;

    void flatten(TreeNode* root) {

        // Base case:
        // If the tree/subtree is empty, nothing to flatten.
        if (root == NULL)
            return;

        // Process the right subtree first.
        // We go Right -> Left -> Root (Reverse Preorder).
        flatten(root->right);

        // Process the left subtree.
        flatten(root->left);

        // The flattened tree must have no left pointers.
        root->left = NULL;

        // Connect the current node to the previously processed node.
        // 'nextRight' represents the next node in preorder traversal.
        root->right = nextRight;

        // Make the current node the new 'nextRight'
        // for the next node processed while recursion unwinds.
        nextRight = root;
    }
};

/*
    Traversal used:
        Right -> Left -> Root

    Why?
    Normal preorder is:
        Root -> Left -> Right

    We process it in reverse so that while coming back
    from recursion, we can easily connect each node's
    right pointer to the previously processed node.

    Example:
             1
            / \
           2   5
          /     \
         3       6

    Flattened result:
        1 -> 2 -> 3 -> 5 -> 6

    Time Complexity: O(n)
        Every node is visited exactly once.

    Space Complexity: O(h)
        Due to the recursive call stack,
        where h is the height of the tree.
        Worst case: O(n)
        Balanced tree: O(log n)

    Important:
    'nextRight' must be a class variable.
    If declared inside flatten(), every recursive call
    would create a new nextRight and the connection would
    be lost.
*/