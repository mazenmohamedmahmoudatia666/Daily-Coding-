class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        // 10 20 30 40

        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr)
            if (!rankMap.count(num))
                rankMap[num] = rank++;

        for (int& num : arr)
            num = rankMap[num];

        return arr;
    }
};
