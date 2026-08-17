class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; i++) P[i + 1] = P[i] + stoneValue[i];

        const long long NEG = LLONG_MIN / 2;
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        vector<int> leftPtr(n), rightPtr(n);
        vector<long long> leftAcc(n, NEG), rightAcc(n, NEG);
        for (int i = 0; i < n; i++) leftPtr[i] = i - 1;
        for (int j = 0; j < n; j++) rightPtr[j] = j + 1;

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                long long total = P[j + 1] - P[i];

                // extend left-kept pointer: largest k with 2*sum(i,k) <= total
                while (leftPtr[i] + 1 <= j - 1 &&
                       2 * (P[leftPtr[i] + 2] - P[i]) <= total) {
                    leftPtr[i]++;
                    int k = leftPtr[i];
                    long long val = dp[i][k] + (P[k + 1] - P[i]);
                    leftAcc[i] = max(leftAcc[i], val);
                }
                long long maxLeft = (leftPtr[i] >= i) ? leftAcc[i] : NEG;

                // extend right-kept pointer: smallest q with 2*sum(i,q-1) >= total
                while (rightPtr[j] - 1 >= i + 1 &&
                       2 * (P[rightPtr[j] - 1] - P[i]) >= total) {
                    rightPtr[j]--;
                    int q = rightPtr[j];
                    long long val = dp[q][j] + (P[j + 1] - P[q]);
                    rightAcc[j] = max(rightAcc[j], val);
                }
                long long maxRight = (rightPtr[j] <= j) ? rightAcc[j] : NEG;

                dp[i][j] = max(maxLeft, maxRight);
            }
        }

        return (int)dp[0][n - 1];
    }
};