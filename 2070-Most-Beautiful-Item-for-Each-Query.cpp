class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res;
        int n = items.size();
        
        // Sort items by price and accumulate maximum beauty for each price
        sort(items.begin(), items.end());
        
        vector<int> prices, max_beauty;
        int current_max_beauty = 0;
        
        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            current_max_beauty = max(current_max_beauty, beauty);
            prices.push_back(price);
            max_beauty.push_back(current_max_beauty); // Track max beauty at each price
        }
        
        // For each query, find the maximum beauty affordable within the budget
        for (int price_query : queries) {
            // Binary search to find the max affordable beauty for the query price
            auto it = upper_bound(prices.begin(), prices.end(), price_query);
            if (it == prices.begin()) {
                res.push_back(0); // No items affordable
            } else {
                int index = it - prices.begin() - 1; // Index of the max affordable price
                res.push_back(max_beauty[index]);
            }
        }
        
        return res;
    }
};
