class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                // find rightmost node of left subtree
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }

                // connect right subtree
                prev->right = curr->right;

                // move left to right
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
