class Solution {
public:
    int longestPalindrome(string s) {

        vector<int> freq1(26,0); // lowerCase
        vector<int> freq2(26,0); // upperCase

        for(char c : s) {
            if(c >= 'a' && c <= 'z') freq1[c - 'a']++;
            else freq2[c - 'A']++;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++){
            // LowerCase
            if(freq1[i] % 2){ // odd freqCount
                ans += freq1[i] - 1;
                freq1[i] = 1;
            }else{ // even freqCount
                ans += freq1[i];
                freq1[i] = 0; 
            }
            // UpperCase
            if(freq2[i] % 2){ 
                ans += freq2[i] - 1;
                freq2[i] = 1; 
            }else{ 
                ans += freq2[i]; 
                freq2[i] = 0;
            }
        }

        for(int i = 0; i < 26; i++){
            if(freq1[i] == 1 || freq2[i] == 1){
                return ans+1;
            }
        }

        return ans;
    }
};