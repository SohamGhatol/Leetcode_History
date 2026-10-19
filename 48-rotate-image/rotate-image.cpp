class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        //Firstly swap the rows and columns
        for (int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse every  row for 90 deg clockwise rotation
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};