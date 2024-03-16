class Solution {
public:
    bool possible(vector<int>& bloomDay, int total_bouquets, int flowers_per_boquet, int waiting_days) {
        bool result = false; // Initialize the result to false
        int adj_flowers = 0, bouquets = 0;

        for (int i = 0; i < (int)bloomDay.size(); ++i) {
            if (bloomDay[i] <= waiting_days) {
                ++adj_flowers;

                if (adj_flowers >= flowers_per_boquet) {
                    adj_flowers = 0;
                    ++bouquets;

                    if (bouquets == total_bouquets) {
                        result = true; // Update result to true if the required number of bouquets is achieved
                        break; // No need to continue iterating
                    }
                }
            } else {
                adj_flowers = 0;
            }
        }

        return result; // Return the result
    }

    int minDays(vector<int>& bloomDay, int total_bouquets, int flowers_per_boquet) {
        if (total_bouquets > (int)bloomDay.size() / flowers_per_boquet)
            return -1;

        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end());

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (possible(bloomDay, total_bouquets, flowers_per_boquet, mid))
                end = mid;
            else
                start = mid + 1;
        }

        return start;
    }
};
