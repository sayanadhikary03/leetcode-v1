/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    // Step 1: Store parent of every node
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* current = q.front();
            q.pop();

            // Store left child's parent
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }

            // Store right child's parent
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // --------------------------------
        // STEP 1: Create child -> parent map
        // --------------------------------
        unordered_map<TreeNode*, TreeNode*> parent_track;

        markParents(root, parent_track);


        // --------------------------------
        // STEP 2: BFS starting from target
        // --------------------------------
        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int currentLevel = 0;


        // --------------------------------
        // STEP 3: Move level by level
        // --------------------------------
        while (!q.empty()) {

            // If we have reached distance k,
            // don't go to the next level
            if (currentLevel == k)
                break;

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* current = q.front();
                q.pop();


                // --------------------------------
                // Move LEFT
                // --------------------------------
                if (current->left &&
                    !visited[current->left]) {

                    q.push(current->left);
                    visited[current->left] = true;
                }


                // --------------------------------
                // Move RIGHT
                // --------------------------------
                if (current->right &&
                    !visited[current->right]) {

                    q.push(current->right);
                    visited[current->right] = true;
                }


                // --------------------------------
                // Move to PARENT
                // --------------------------------
                if (parent_track[current] &&
                    !visited[parent_track[current]]) {

                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }

            currentLevel++;
        }


        // --------------------------------
        // STEP 4: Queue now contains
        // nodes exactly k distance away
        // --------------------------------
        vector<int> result;

        while (!q.empty()) {

            TreeNode* current = q.front();
            q.pop();

            result.push_back(current->val);
        }

        return result;
    }
};