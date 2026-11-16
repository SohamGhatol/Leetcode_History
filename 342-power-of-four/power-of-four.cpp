class Solution {
public:
    bool isPowerOfFour(int n) {

        // Power of four must be positive
        if (n <= 0) return false;

        // Check if exactly one bit is set
        if ((n & (n - 1)) != 0) return false;

        // Check whether the set bit is at an even position
        return (n & 0x55555555) != 0;
    }
};