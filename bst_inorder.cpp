class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        vector<int> left = inorderTraversal(root->left);
        
        vector<int> right = inorderTraversal(root->right);

        res.insert(res.end(),left.begin(),left.end());
        res.push_back(root->val);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};
