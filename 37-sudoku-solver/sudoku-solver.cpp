class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char digit){
        // vertical
        for(int i = 0; i < 9; i++){
            if(board[i][c] == digit){
                return false;
            }
        }
        // horizontal
        for(int j = 0; j < 9; j++){
            if(board[r][j] == digit){
                return false;
            }
        }
        // 3x3 grid
        int stRow = (r/3)*3;
        int stCol = (c/3)*3;

        for(int i = stRow; i < stRow + 3; i++){
            for(int j = stCol; j < stCol + 3; j++){
                if(board[i][j] == digit) return false;
            }
        }

        return true;
    }
    bool sudokuSolver(vector<vector<char>>& board, int r, int c){
        if(r == 9) {
            return true;
        }

        int newRow = r;
        int newCol = c+1;

        if(c + 1 == 9){
            newRow = r + 1;
            newCol = 0; 
        }

        if(board[r][c] != '.'){
            return sudokuSolver(board, newRow, newCol);
        }

        for(char digit = '1'; digit <= '9'; digit++){
            if(isSafe(board,r,c,digit)){
                board[r][c] = digit;
                if(sudokuSolver(board, newRow, newCol)){
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }
};