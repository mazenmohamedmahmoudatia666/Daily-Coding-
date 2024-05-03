#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = version1.size(); // Length of version1
        int s2 = version2.size(); // Length of version2
        
        int i = 0, j = 0; // Pointers for version1 and version2
        for (i = 0, j = 0; i < s1 || j < s2; i++, j++) {
            int num1 = 0, num2 = 0; // Integers to store the current segment of version numbers
            // Parse version1 segment
            while (i < s1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0'); // Convert character to integer
                i++; // Move to the next character
            }
            // Parse version2 segment
            while (j < s2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0'); // Convert character to integer
                j++; // Move to the next character
            }
            
            // Compare the parsed segments
            if (num1 > num2) return 1; // If version1 segment is greater, return 1
            if (num1 < num2) return -1; // If version2 segment is greater, return -1
        }
        
        return 0; // If versions are equal
    }
};
