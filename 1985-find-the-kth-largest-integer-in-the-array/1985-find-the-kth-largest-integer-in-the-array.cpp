class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // Compare numeric strings without converting to actual integers (avoids overflow,
        // since nums[i].length() can be up to 100 digits — way beyond long long range).
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() > b.size(); // longer numeric string = larger value
            }
            return a > b; // same length: standard lexicographic comparison works for digit strings
        });
        
        return nums[k - 1];
    }
};