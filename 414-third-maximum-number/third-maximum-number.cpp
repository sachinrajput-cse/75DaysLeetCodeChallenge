class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();

        long long firstMax = LLONG_MIN; 
        for(int i = 0; i < n; i++){
            if(nums[i] > firstMax) firstMax = nums[i];
        }

        long long  secondMax = LLONG_MIN;
        for(int i = 0; i < n; i++){
            if(firstMax != nums[i] && nums[i] > secondMax) secondMax = nums[i];
        }

        long long  thirdMax = LLONG_MIN;
        for(int i = 0; i < n; i++){
            if(firstMax != nums[i] && secondMax != nums[i] && nums[i] > thirdMax) 
                thirdMax = nums[i];
        }

        if(thirdMax == LLONG_MIN){
            return firstMax;
        }
        return thirdMax;
    }
};