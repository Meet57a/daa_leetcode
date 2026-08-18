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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        return buildBalanced(sorted, 0, sorted.size() - 1);
    }
    
private:
    void inorder(TreeNode* node, vector<int>& sorted) {
        if (!node) return;
        inorder(node->left, sorted);
        sorted.push_back(node->val);
        inorder(node->right, sorted);
    }
    
    TreeNode* buildBalanced(vector<int>& sorted, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(sorted[mid]);
        
        node->left = buildBalanced(sorted, left, mid - 1);
        node->right = buildBalanced(sorted, mid + 1, right);
        
        return node;
    }
};