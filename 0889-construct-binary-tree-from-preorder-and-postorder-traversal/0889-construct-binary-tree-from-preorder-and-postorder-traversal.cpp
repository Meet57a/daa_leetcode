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
    vector<int> pre, post;
    unordered_map<int, int> postIndex; // value -> index in postorder
    int preIdx = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        pre = preorder;
        post = postorder;
        for (int i = 0; i < post.size(); i++) {
            postIndex[post[i]] = i;
        }
        return build(0, post.size() - 1);
    }

    // Builds the subtree whose postorder range is [postStart, postEnd] (inclusive)
    TreeNode* build(int postStart, int postEnd) {
        TreeNode* root = new TreeNode(pre[preIdx]);
        preIdx++;

        // Single node subtree (no children left to assign)
        if (postStart == postEnd) {
            return root;
        }

        // The next preorder value is the root of the left subtree
        int leftRootVal = pre[preIdx];
        int leftRootPostIdx = postIndex[leftRootVal];

        // Left subtree spans postStart .. leftRootPostIdx
        root->left = build(postStart, leftRootPostIdx);

        // If there's anything left before postEnd-1 (root itself is at postEnd), build right subtree
        if (leftRootPostIdx < postEnd - 1) {
            root->right = build(leftRootPostIdx + 1, postEnd - 1);
        }

        return root;
    }
};