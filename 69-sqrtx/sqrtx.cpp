class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Use long long to avoid overflow in mid * mid
            long long square = 1LL * mid * mid;

            if (square == x) {
                return mid;
            }
            else if (square < x) {
                ans = mid;          // Save possible answer
                left = mid + 1;     // Search for a larger square root
            }
            else {
                right = mid - 1;    // Search the left half
            }
        }

        return ans;
    }
};