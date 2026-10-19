class Solution {
public:
    vector<int> getRow(int row) {
        long long ans=1;
        vector<int> ansRow;
        ansRow.push_back(1); //First element is always 1

        for (int col=0;col<row; col++) {
            ans=ans*(row-col); // Calculate next element
            ans =ans/(col+1);//Divide to get exact value
            ansRow.push_back((int)ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i=0;i<numRows;i++) {
            ans.push_back(getRow(i)); // Generate each row
        }
        return ans;
    }
};