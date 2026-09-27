class Solution {
public:
    set<vector<int>> mySet;
    void backtrack(vector<int>& nums, vector<int>& permutation, vector<bool>& vis){
        if(permutation.size() == nums.size()){
            mySet.insert(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) continue;

            permutation.push_back(nums[i]);
            vis[i] = true;

            backtrack(nums, permutation, vis);

            permutation.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        vector<int> permutation;

        backtrack(nums, permutation, vis);

        vector<vector<int>> ans;

        for(auto permut : mySet){
            ans.push_back(permut);
        }
        return ans;
    }
};