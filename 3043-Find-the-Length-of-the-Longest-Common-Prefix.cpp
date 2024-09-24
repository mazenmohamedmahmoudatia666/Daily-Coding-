class Solution {
public:
    int longestCommonPrefix(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<string, int> mp;

        for(int num:nums1){
            string str = to_string(num); // 1
            string prefix = "";
            for(char ch:str){
                prefix += ch;
                mp[prefix]++;
            }
        }

        int maxLen = 0;
        for(int num:nums2){
            string str = to_string(num);
            string prefix = "";
            for(char ch:str){
                prefix += ch;
                if(mp.find(prefix) != mp.end()){
                    maxLen = max(maxLen, static_cast<int>(prefix.length()));
                }
            }
        }
        return maxLen;
    }
};