class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(r > l){
            if(s[l] != s[r]){
                return false;
            }
            l++; r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        
        int count = 0, st = 0;
        for(int r = k-1; r < n; r++){
            for(int len = k; len <= r - st + 1; len++){
                int l = r - len + 1;
                if(isPalindrome(s,l,r)){
                    count++;
                    st = r + 1;
                    break;
                }
            }
        }
        return count;
    }
};