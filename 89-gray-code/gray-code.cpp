class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        //Generate all 2^n Gray code no.
        for (int i=0;i<(1<<n);i++) {
            //XOR the number with its right-shifted 
            int gray =i^(i>>1);
            ans.push_back(gray);
        }
        return ans;
    }
};