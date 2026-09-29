class Solution {
public:
    vector<vector<int>> combinations;
    void Combinations(int n, int k, int choice, vector<int> combination){
        combination.push_back(choice);
        
        if(combination.size() == k){
            combinations.push_back(combination);
            return;
        }

        for(int i = choice + 1; i <= n; i++){
            Combinations(n, k, i, combination);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        if(k > n) return {};

        for(int i = 1; i <= n; i++){
            vector<int> combination;
            Combinations(n, k, i, combination);
        }

        return combinations;
    }
};