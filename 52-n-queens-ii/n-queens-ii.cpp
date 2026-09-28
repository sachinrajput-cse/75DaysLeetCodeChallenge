class Solution {
public:
    int solutionCount = 0;
    bool isSafe(vector<vector<char>>& board, int r, int c){
        int n = board.size();
        
        // Horizontal 
        for(int i = 0; i < board.size(); i++){
            if(board[r][i] == 'Q') return false;
        }
        
        // Vertical 
        for(int i = 0; i < r; i++){
            if(board[i][c] == 'Q') return false;
        }
        
        // Diagonal Left
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        
        // Diagonal Right
        for(int i = r, j = c; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    void NQueens(vector<vector<char>>& board, int r){
        int n = board.size();
        
        if(r == n) {
            solutionCount++;
            return;
        }
        
        for(int c = 0; c < n; c++){
            if(isSafe(board,r,c)) {
                board[r][c] = 'Q';
                NQueens(board,r+1);
                board[r][c] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
	
	    NQueens(board,0);

        return solutionCount;
    }
};