class Solution {
public:
    TreeNode* buildToBST(vector<int>& nums,int left,int right) {
        if(left > right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildToBST(nums,left,mid-1);
        root->right = buildToBST(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int> nums){
        return buildToBST(nums,0,nums.size()-1);
    }
};
