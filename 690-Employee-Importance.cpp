#include <vector>
#include <unordered_map>

using namespace std;

// Definition for Employee.
/*class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    unordered_map<int, Employee*> id_to_emp;

    int dfs(int id) {
        Employee *emp = id_to_emp[id];
        int result = emp->importance;
        for (auto &subemp : emp->subordinates)
            result += dfs(subemp);
        return result;
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto &emp : employees)
            id_to_emp[emp->id] = emp;

        return dfs(id);
    }
};
