class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Brute Force Approach 
        // TC : O(n) , SC : O(n).

        vector<int> freq(100001,0);
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        vector<int> duplicates;
        for(int i = 0; i < 100001; i++){
            if(freq[i] == 2) duplicates.push_back(i);
        }

        return duplicates;
    }
};