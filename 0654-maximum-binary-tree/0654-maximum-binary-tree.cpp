/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stack; // monotonically decreasing stack

        for (int num : nums) {
            TreeNode* cur = new TreeNode(num);

            // Pop all smaller elements; the last one popped becomes cur's left child
            while (!stack.empty() && stack.back()->val < num) {
                cur->left = stack.back();
                stack.pop_back();
            }

            // If stack isn't empty, cur becomes the right child of the new top
            if (!stack.empty()) {
                stack.back()->right = cur;
            }

            stack.push_back(cur);
        }

        // The bottom of the stack is the root (largest overall value)
        return stack.front();
    }
};