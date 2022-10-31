class Solution {
public:
    vector<vector<string>> ans;
    bool issafe(int row,int col,vector<string>& board){
        for(int i=0;i<col;i++){if(board[row][i]=='Q'){return false;}}
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){if(board[i][j]=='Q'){return false;}}
        for(int i=row,j=col;i<board.size() && j>=0;i++,j--){if(board[i][j]=='Q'){return false;}}
        return true;
    }
    bool solverec(int col,vector<string>& board){
        if(col==board.size()){ans.push_back(board);};
        for(int i=0;i<board.size();i++){
            if(issafe(i,col,board)){
                board[i][col]='Q';
                if(solverec(col+1,board)) return true;
                board[i][col]='.';
            }   
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        string dots = "";
        for(int i=0;i<n;i++) dots.push_back('.');
        vector<string> board(n, dots);             
        solverec(0,board);
        return ans;
    }    
};
