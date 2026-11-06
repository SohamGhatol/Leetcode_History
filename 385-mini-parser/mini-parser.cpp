/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s){

        //Case1:The input is a single integer
        if (s[0] !='[') {
            return NestedInteger(stoi(s));
        }

        //Create an empty nested list
        NestedInteger result;
        //Traverse the string
        for(int i=1;i<s.size();) {
            //Skip commas and closing brackets
            if (s[i]==',' || s[i]==']') {
                i++;
            }

            //If a nested list starts
            else if(s[i]== '[') {
                int start = i;
                int count = 0;

                //Find the matching closing bracket
                do{
                    if(s[i] == '[') count++;
                    else if(s[i] == ']') count--;
                    i++;
                } while (count > 0);

                //Extract the nested substring
                string sub = s.substr(start, i - start);

                //Recursively deserialize and add it
                result.add(deserialize(sub));
            }

            //If the current character is a digit or minus sign
            else{
                int start = i;
                //Read the complete integer
                while (i<s.size() && (isdigit(s[i]) || s[i] == '-')) {
                    i++;
                }

                //Convert string to integer and add it
                result.add(NestedInteger(stoi(s.substr(start, i - start))));
            }
        }

        return result;
    }
};