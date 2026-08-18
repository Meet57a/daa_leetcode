class Solution {
public:
    unordered_map<int, vector<int>> memo;

    vector<int> beautifulArray(int n) {
        return construct(n);
    }

private:
    vector<int> construct(int n) {
        if (memo.count(n)) {
            return memo[n];
        }

        if (n == 1) {
            return memo[1] = {1};
        }

        // Recursively build beautiful arrays for the "odd" half and "even" half
        vector<int> left = construct((n + 1) / 2);   // will become odd numbers
        vector<int> right = construct(n / 2);         // will become even numbers

        vector<int> result;
        result.reserve(n);

        // Transform left -> odd numbers: 2*x - 1
        for (int x : left) {
            result.push_back(2 * x - 1);
        }
        // Transform right -> even numbers: 2*x
        for (int x : right) {
            result.push_back(2 * x);
        }

        memo[n] = result;
        return result;
    }
};