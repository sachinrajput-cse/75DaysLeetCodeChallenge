class Solution {
public:
    vector<vector<int>> ans;
    void permutations(string str, vector<int> permutation){
        if(str.size() == 0) {
            ans.push_back(permutation); 
            return;
        }

        for(int i = 0; i < str.size(); i++){
            permutation.push_back(int(str[i]));
            string newStr = str.substr(0,i) + str.substr(i+1, str.size() - i - 1);
            permutations(newStr, permutation);
            permutation.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        string str = "";

        for(int num : nums) 
            str += char(num);
        
        vector<int> permutation;
        permutations(str, permutation);

        return ans;
    }
};