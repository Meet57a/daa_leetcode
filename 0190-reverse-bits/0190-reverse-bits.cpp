class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            // Shift result left
            result <<= 1;

            // Add last bit of n
            result |= (n & 1);

            // Move to next bit
            n >>= 1;
        }

        return result;
    }
};