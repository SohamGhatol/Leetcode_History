class Solution {
public:
    string addBinary(string a, string b) {
     int i =a.size()-1,j=b.size()-1,carry = 0;
        string ans = "";

        //Continue while digits or carry are remaining
        while (i>=0||j>=0||carry) {
            int sum = carry;
            //Add digit from first string
            if (i>= 0) {
                sum +=a[i]-'0';
                i--;
            }

            // Add digit from second string
            if (j>=0) {
                sum+=b[j]-'0';
                j--;
            }

            //Store current binary digit
            ans+=(sum%2)+'0';
            //Calculate carry for next position
            carry=sum/2;
        }

        //Reverse because addition was performed right to left
        reverse(ans.begin(),ans.end());
        return ans;
    }
};