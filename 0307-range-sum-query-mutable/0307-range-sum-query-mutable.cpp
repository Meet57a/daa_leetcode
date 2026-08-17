class NumArray {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateTree(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) {
            updateTree(node * 2, start, mid, index, val);
        } else {
            updateTree(node * 2 + 1, mid + 1, end, index, val);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int start, int end, int left, int right) {
        // Completely outside range
        if (right < start || end < left) {
            return 0;
        }

        // Completely inside range
        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;

        int leftSum = query(node * 2, start, mid, left, right);
        int rightSum = query(node * 2 + 1, mid + 1, end, left, right);

        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};