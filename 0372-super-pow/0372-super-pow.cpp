class Solution {
public:
    const int MOD = 1337;

    int power(int a, int b) {
        int result = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {
        a %= MOD;

        int result = 1;

        for (int digit : b) {
            result = power(result, 10);
            result = (result * power(a, digit)) % MOD;
        }

        return result;
    }
};