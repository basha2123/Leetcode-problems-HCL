class Solution {
public:
    bool ismirror(TreeNode* left,TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;
        return ismirror(left->left,right->right) && ismirror(left->right,right->left);
        
    }
    bool isSymmetric(TreeNode *root){
        if(root == NULL){
            return true;
        }
        return ismirror(root->left,root->right);
    }
};
