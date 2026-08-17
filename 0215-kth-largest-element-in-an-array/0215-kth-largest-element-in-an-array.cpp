class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int pivot = nums[left + (right - left) / 2];

            int low = left;
            int mid = left;
            int high = right;

            // 3-way partition:
            // [left ... low-1]   < pivot
            // [low ... high]     == pivot
            // [high+1 ... right] > pivot

            while (mid <= high) {
                if (nums[mid] < pivot) {
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                }
                else if (nums[mid] > pivot) {
                    swap(nums[mid], nums[high]);
                    high--;
                }
                else {
                    mid++;
                }
            }

            // target is in the smaller section
            if (target < low) {
                right = low - 1;
            }
            else if (target > high) {
                left = high + 1;
            }
            else {
                return nums[target];
            }
        }

        return -1;
    }
};