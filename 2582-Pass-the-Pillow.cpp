class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1; // Start with the first person
        bool forward = true; // Direction flag

        while (time--) {
            if (forward) {
                if (i == n) {
                    forward = false;
                    i--;
                } else {
                    i++;
                }
            } else {
                if (i == 1) {
                    forward = true;
                    i++;
                } else {
                    i--;
                }
            }
        }

        return i;
    }
};
