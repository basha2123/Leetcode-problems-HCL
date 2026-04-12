class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr) return res;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            int n=q.size();   // no of nodes in that level = curr queue size
            vector<int>v;

            for(int i=0;i<n;i++){ //for all nodes in that level, keep in v
             TreeNode* node=q.front();
             q.pop();
             if(node->left!=NULL) q.push(node->left);
             if(node->right!=NULL) q.push(node->right);
             v.push_back(node->val);
            }

            res.push_back(v);

        }
        return res;
    }
};
