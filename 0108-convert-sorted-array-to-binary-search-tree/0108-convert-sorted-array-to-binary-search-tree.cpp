class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Find middle element
        int mid = left + (right - left) / 2;

        // Middle becomes root
        TreeNode* root = new TreeNode(nums[mid]);

        // Left half becomes left subtree
        root->left = build(nums, left, mid - 1);

        // Right half becomes right subtree
        root->right = build(nums, mid + 1, right);

        return root;
    }
};