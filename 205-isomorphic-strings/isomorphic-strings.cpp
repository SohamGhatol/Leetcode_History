class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((s[i]==s[j]&&t[i]!=t[j])||(t[i]==t[j]&&s[i]!=s[j])){
                    return false;
                }
            }
        }

        return true;
        
    }
};