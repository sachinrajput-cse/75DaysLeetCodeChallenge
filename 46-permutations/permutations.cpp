class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums, vector<bool>& vis, vector<int>& permutation){ // TC : O(n!) & SC : O(n!)
        if(permutation.size() == nums.size()) {
            ans.push_back(permutation); 
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) continue;

            permutation.push_back(nums[i]);
            vis[i] = true;

            backtracking(nums, vis, permutation);

            permutation.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> vis(nums.size(),false);
        vector<int> permutation;

        backtracking(nums, vis, permutation);

        return ans;
    }
};