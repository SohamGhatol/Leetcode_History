
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        //Store dictionary words for O(1) average lookup
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        // dp[i] = true means first i characters can be segmented
        vector<bool> dp(n+1, false);

        // Empty string can always be segmented
        dp[0]=true;
        // Check every prefix of the string
        for (int i=1;i<=n;i++) {
            // Try every possible last word
            for (int j= 0;j<i;j++) {

                // Previous part must be valid
                if (dp[j] && st.count(s.substr(j,i - j))) {
                    // Current prefix can be segmented
                    dp[i] = true;
                    break;
                }
            }
        }

        // Can the entire string be segmented?
        return dp[n];
    }
};
