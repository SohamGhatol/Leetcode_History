class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        // Check every possible starting position
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Match needle with haystack starting from i
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // If all characters matched, return starting index
            if (j == m) {
                return i;
            }
        }

        // No occurrence found
        return -1; 
    }
};