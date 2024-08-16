class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        int change = accumulate(bills.begin(), bills.end(), 0);  // Total value of bills

        for (int bill : bills) {
            if (bill == 5) {
                five++;  // Received a $5 bill
            } else if (bill == 10) {
                if (five > 0) {
                    five--;  // Give one $5 as change
                    ten++;   // Received a $10 bill
                } else {
                    return false;  // Can't give change
                }
            } else {
                if (ten > 0 && five > 0) {
                    ten--;  // Give one $10
                    five--; // Give one $5
                } else if (five >= 3) {
                    five -= 3;  // Give three $5 bills as change
                } else {
                    return false;  // Can't give change
                }
            }
        }
        return true;  // If change was provided for all
    }
};
