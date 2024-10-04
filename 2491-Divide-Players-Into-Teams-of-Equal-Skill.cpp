#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Step 1: Sort the skill array
        sort(skill.begin(), skill.end());
        // 1 2 3 3 4 5 
        int n = skill.size();
        
        // Step 2: Calculate the expected total skill for each team
        int targetSkill = skill[0] + skill[n - 1]; // Skill of the first and last player
        long long chemistrySum = 0;

        // Step 3: Pair players and calculate chemistry
        for (int i = 0; i < n / 2; ++i) {
            int teamSkill = skill[i] + skill[n - 1 - i]; // Pairing players
            
            // Check if the current pair matches the target skill
            if (teamSkill != targetSkill) {
                return -1; // If not, return -1
            }

            // Calculate the chemistry for this team
            chemistrySum += (long long)skill[i] * skill[n - 1 - i]; // Calculate chemistry
        }

        return chemistrySum; // Return the sum of all chemistries
    }
};

