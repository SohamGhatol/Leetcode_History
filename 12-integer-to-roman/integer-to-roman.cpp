class Solution {
public:
    string intToRoman(int num) {
        //Roman values arranged in descending order
        vector<int> values = {1000, 900, 500, 400, 100, 90,50, 40, 10, 9, 5, 4, 1};
        //Corresponding Roman symbols
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC","L", "XL", "X", "IX", "V", "IV", "I"};

        string ans = "";

        //Process every Roman value from largest to smallest
        for (int i = 0; i < values.size(); i++) {
            //Use the current symbol as many times as possible
            while (num >= values[i]) {
                ans+= symbols[i];  //Add Roman symbol
                num-= values[i];   //Reduce remaining number
            }
        }
        return ans;
    }
};
