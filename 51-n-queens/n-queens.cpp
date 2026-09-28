class Solution {
public:
    vector<vector<string>> solutions;
    void addInSolutions(vector<vector<char>>& board){
        int n = board.size();
        vector<string> solution;
        for(int r = 0; r < n; r++){
            string str = "";
            for(int c = 0; c < n; c++){
                str += board[r][c];
            }
            solution.push_back(str);
        }
        solutions.push_back(solution);
    }
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
            addInSolutions(board);
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
    vector<vector<string>> solveNQueens(int n) {
	    vector<vector<char>> board(n, vector<char>(n, '.'));
	
	    NQueens(board,0);

        return solutions;
    }
};