class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lastS[256];
        int lastT[256];

        fill(lastS, lastS + 256, -1);
        fill(lastT, lastT + 256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (lastS[(unsigned char)s[i]] !=
                lastT[(unsigned char)t[i]]) {
                return false;
            }

            lastS[(unsigned char)s[i]] = i;
            lastT[(unsigned char)t[i]] = i;
        }

        return true;
    }
};