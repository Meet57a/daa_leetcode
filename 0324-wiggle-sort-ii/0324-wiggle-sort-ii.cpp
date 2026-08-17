class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Find median
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        int median = nums[n / 2];

        // Virtual index
        auto index = [n](int i) {
            return (1 + 2 * i) % (n | 1);
        };

        int left = 0;
        int i = 0;
        int right = n - 1;

        // 3-way partition
        while (i <= right) {
            int idx = index(i);

            if (nums[idx] > median) {
                swap(nums[index(left)], nums[idx]);
                left++;
                i++;
            }
            else if (nums[idx] < median) {
                swap(nums[idx], nums[index(right)]);
                right--;
            }
            else {
                i++;
            }
        }
    }
};