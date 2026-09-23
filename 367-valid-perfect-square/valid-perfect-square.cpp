class Solution {
public:
    bool isPerfectSquare(int num) {
        bool ans = false;
        for(long long i = 1; i <= num; i++){
            if(i*i == num){
                ans = true;
                break;
            }else if(i*i > num){
                break;
            }
        }
        return ans;
    }
};