class Solution {
public:
        vector<vector <string>> ans; 
        vector <string> board;
        vector <bool> col,diag1,diag2;
        int n;

        void solve(int row){
            if (row==n){
                ans.push_back(board);
                return;
            }
            //Trying to place Q in each column
            for(int x=0;x<n;x++){
                int d1=row-x+n-1;
                int d2=row+x;

                //Skip positions attacked by another queen in simple terms skip the Diagonal columns
                if(col[x]||diag1[d1]||diag2[d2])
                    continue;

                //Place Queen
                board[row][x] = 'Q';
                col[x]=diag1[d1] = diag2[d2] = true;

                solve(row + 1);

                //Backtrack:remove the queen and free its lines
                board[row][x]='.';
                col[x]=diag1[d1]=diag2[d2] =false;
            }
        }
    public:
    vector<vector<string>> solveNQueens(int n){
        this->n =n;
        ans.clear();

        board.assign(n,string(n,'.'));
        col.assign(n,false);
        diag1.assign(2*n-1, false);
        diag2.assign(2*n-1, false);

        solve(0);
        return ans;
    }
};