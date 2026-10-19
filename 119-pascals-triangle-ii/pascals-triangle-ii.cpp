class Solution {
public:

    long long nCr(int n, int r){
        long long ans=1;
        for(int i=0;i<r;i++){
            ans=ans*(n-i);
            ans=ans/(i+1);
        }
        return ans;//for binomial coefficient
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ansRow;
        for(int col=0;col<=rowIndex;col++){
            ansRow.push_back(nCr(rowIndex,col));//Calculation of each element of nCr
        }
    return ansRow;

    }
};
