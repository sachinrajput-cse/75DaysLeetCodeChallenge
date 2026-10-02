class Solution {
public:
    vector<string> ans;
    void combinations(int count1, int count2, string combination){
        // Choice Open Bracket 
        if(count1) combinations(count1 - 1, count2, combination + "(");

        // Choice Close Bracket
        if(count2 && count1 <= count2 - 1) combinations(count1, count2 - 1, combination + ")");

        // Base Condition
        if(count1 == 0 && count2 == 0){
            ans.push_back(combination);
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        int count1 = n; // Open Bracket Count;
        int count2 = n; // Close Bracket Count;
        combinations(count1 , count2, "");
        return ans;
    }
};