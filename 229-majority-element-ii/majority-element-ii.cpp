class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> myMap; // <number,freq>

        for(int num : nums){
            myMap[num]++;
        }

        vector<int> ans;

        for(auto it : myMap){
            if(it.second > nums.size()/3){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};