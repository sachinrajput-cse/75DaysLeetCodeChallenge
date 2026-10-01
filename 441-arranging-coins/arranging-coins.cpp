class Solution {
public:
    int arrangeCoins(int n) {
        int terminate = n, completeRows = 1;
        for(int i = 1; i <= terminate; i++){
            if(n - i < 0) {
                completeRows = i-1;
                break;
            }
            n -= i;
        }
        return completeRows;
    }
};