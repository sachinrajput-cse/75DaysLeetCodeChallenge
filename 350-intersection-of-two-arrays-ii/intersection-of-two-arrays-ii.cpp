class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq1(1001,0);
        vector<int> freq2(1001,0);

        for(int i = 0; i < nums1.size(); i++){
            freq1[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            freq2[nums2[i]]++;
        }

        vector<int> result;
        for(int i = 0; i < 1001; i++){
            int freq = min(freq1[i], freq2[i]);
            for(int f = 0; f < freq; f++){
                result.push_back(i);
            }
        }
        return result;
    }
};