class Solution {
public:
    int minimumPushes(string word) {

        vector<int> mp(26,0);

        for(auto &c: word){
            mp[c-'a']++;
        }
        
        sort(mp.begin(),mp.end(),greater<int>());

        int ans = 0;
        int push = 1;
        int keyCnt = 0;

        for(auto &occur : mp){

            if(occur == 0) break;

            ans += occur * push;
            keyCnt++;

            if(keyCnt % 8 == 0) push++;
            
        }

        return ans;
        
    }
};