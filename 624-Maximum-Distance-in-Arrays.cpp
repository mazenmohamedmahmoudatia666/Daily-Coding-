//  so focus mazen 
// in this problem we will start with first array and find the smallest and biggest element ;
// then we will compare these two element with second array and so on ;
// the compare will be like that biggest one in second array with smallest one with first array
// and the biggest one in first array with smallest one with second array





class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max(max_distance, abs(arrays[i].back() - smallest));
            max_distance = max(max_distance, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return max_distance;
    }
};
