class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int postorderIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // Store index of every value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        // Last element of postorder is the root
        postorderIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& postorder, int left, int right) {
        
        if (left > right) {
            return nullptr;
        }

        // Get root from the END of postorder
        int rootValue = postorder[postorderIndex--];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int mid = inorderIndex[rootValue];

        // IMPORTANT:
        // Since we are moving backwards in postorder,
        // build RIGHT subtree first.
        root->right = build(postorder, mid + 1, right);

        root->left = build(postorder, left, mid - 1);

        return root;
    }
};