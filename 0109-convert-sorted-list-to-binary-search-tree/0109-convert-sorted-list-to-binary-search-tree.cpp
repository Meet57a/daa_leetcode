class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // Find middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is the middle node

        // Break the list into left and right parts
        if (prev != nullptr) {
            prev->next = nullptr;
        } else {
            // Only one node
            head = nullptr;
        }

        // Middle node becomes root
        TreeNode* root = new TreeNode(slow->val);

        // Left part
        root->left = sortedListToBST(head);

        // Right part
        root->right = sortedListToBST(slow->next);

        return root;
    }
};